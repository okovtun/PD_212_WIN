#include "Widget.h"
#include "ui_Widget.h"
#include <QStyle>
#include <QFileDialog>
#include <QDir>
#include <QTime>
#include <QToolButton>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	muted = false;

	//				Buttons style:
	ui->pushButtonOpen->setIcon(style()->standardIcon(QStyle::SP_DriveCDIcon));
	ui->pushButtonPrev->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
	ui->pushButtonPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
	ui->pushButtonPause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
	ui->pushButtonStop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
	ui->pushButtonNext->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));
	ui->pushButtonMute->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));



	//				Player init:
	m_player = new QMediaPlayer(this);
	m_player->setVolume(70);
	ui->labelVolume->setText(QString("Volume: ").append(QString::number(m_player->volume())));
	ui->horizontalSliderVolume->setValue(m_player->volume());

	connect(m_player, &QMediaPlayer::positionChanged, this, &Widget::on_position_changed);
	connect(m_player, &QMediaPlayer::durationChanged, this, &Widget::on_duration_changed);

	//				Playlist init:
	m_playlist_model = new QStandardItemModel(this);
	ui->tableViewPlaylist->setModel(m_playlist_model);
	m_playlist_model->setHorizontalHeaderLabels(QStringList() << "Audio track" << "File path");
	ui->tableViewPlaylist->hideColumn(1);
	ui->tableViewPlaylist->horizontalHeader()->setStretchLastSection(true);
	ui->tableViewPlaylist->setEditTriggers(QAbstractItemView::NoEditTriggers);

	m_playlist = new QMediaPlaylist(m_player);
	m_player->setPlaylist(m_playlist);

	connect(ui->pushButtonPause, &QToolButton::clicked, this->m_player, &QMediaPlayer::pause);
	connect(ui->pushButtonStop, &QToolButton::clicked, this->m_player, &QMediaPlayer::stop);
	connect(ui->pushButtonPrev, &QToolButton::clicked, m_playlist, &QMediaPlaylist::previous);
	connect(ui->pushButtonNext, &QToolButton::clicked, m_playlist, &QMediaPlaylist::next);

	load_playlist(DEFAULT_PLAYLIST);

//	connect(m_playlist, &QMediaPlaylist::currentIndexChanged, ui->tableViewPlaylist, &QTableView::selectRow);
	connect(m_playlist, &QMediaPlaylist::currentIndexChanged, ui->tableViewPlaylist,
			[this](int index)
	{
		ui->labelComposition->setText(m_playlist_model->data(m_playlist_model->index(index, 0)).toString());
		this->setWindowTitle("Winamp - " + ui->labelComposition->text());
		ui->tableViewPlaylist->selectRow(index);
	}
			);
	connect(ui->tableViewPlaylist, &QTableView::doubleClicked, m_playlist_model,
			[this](const QModelIndex& index){m_playlist->setCurrentIndex(index.row()); m_player->play();}
			);

	connect(ui->pushButtonCLR, &QToolButton::clicked,
			[this]()
	{
		m_playlist->clear();
		m_playlist_model->clear();
	}
			);
	connect(ui->pushButtonDEL, &QToolButton::click,
			[this]()
	{
		QItemSelectionModel* selection = ui->tableViewPlaylist->selectionModel();
		QModelIndexList rows = selection->selectedRows();
		for(QModelIndexList::iterator it = rows.begin(); it != rows.end(); ++it)
		{
			if(m_playlist->removeMedia(it->row()))
				m_playlist_model->removeRows(it->row(), 1);
		}
	}
			);
}

Widget::~Widget()
{
	save_playlist(DEFAULT_PLAYLIST);
	delete m_player;
	delete ui;
}

void Widget::load_playlist(QString filename)
{
	QString format = filename.split('.').back();
	m_playlist->load(QUrl::fromLocalFile(filename), format.toStdString().c_str());
	for(int i = 0; i<m_playlist->mediaCount(); i++)
	{
		QMediaContent content = m_playlist->media(i);
		QString url = content.canonicalUrl().url();
		QList<QStandardItem*> items;
		items.append(new QStandardItem(QDir(url).dirName()));
		items.append(new QStandardItem(url));
		m_playlist_model->appendRow(items);
	}
}

void Widget::save_playlist(QString filename)
{
	QString format = filename.split('.').last();
	m_playlist->save(QUrl::fromLocalFile(filename), format.toStdString().c_str());
}



void Widget::on_pushButtonOpen_clicked()
{
//	QString file = QFileDialog::getOpenFileName
//			(
//				this,			//Родительское окно
//				tr("Open file"),//Заголовок окна диалога
//				"D:\\Users\\Clayman\\Music\\Sergo",		//Рабочий каталог
//				tr("Audio files (*.mp3 *.flac)")
//				);
//	ui->labelComposition->setText(file.split('/').last());
//	this->setWindowTitle(QString("Winamp - ").append(file.split('/').last()));
//	m_player->setMedia(QUrl::fromLocalFile(file));

	QStringList files = QFileDialog::getOpenFileNames(
				this,
				"Open files",
				"D:\\Users\\Clayman\\Music\\Sergo",
				"Audio files (*.mp3 *.flac)"
				);
	for(QString filesPath: files)
	{
		QList<QStandardItem*> items;
		items.append(new QStandardItem(QDir(filesPath).dirName()));
		items.append(new QStandardItem(filesPath));
		m_playlist_model->appendRow(items);
		m_playlist->addMedia(QUrl(filesPath));
	}
}

void Widget::on_horizontalSliderVolume_valueChanged(int value)
{
	m_player->setVolume(value);
	ui->labelVolume->setText(QString("Volume: ").append(QString::number(m_player->volume())));
}

void Widget::on_pushButtonPlay_clicked()
{
	m_player->play();
}


void Widget::on_position_changed(qint64 position)
{
	ui->horizontalSliderProgress->setValue(position);
	QTime qt_position = QTime::fromMSecsSinceStartOfDay(position);
	ui->labelProgress->setText(QString("Position: ").append(qt_position.toString("mm:ss")));
}

void Widget::on_duration_changed(qint64 duration)
{
	ui->horizontalSliderProgress->setMaximum(duration);
	QTime qt_duration = QTime::fromMSecsSinceStartOfDay(duration);
	ui->labelDuration->setText(QString("Duration: ").append(qt_duration.toString("mm:ss")));
}

void Widget::on_horizontalSliderProgress_sliderMoved(int position)
{
	m_player->setPosition(position);
}

void Widget::on_pushButtonMute_clicked()
{
	muted = !muted;
	m_player->setMuted(muted);
	ui->pushButtonMute->setIcon(style()->standardIcon(muted?QStyle::SP_MediaVolumeMuted:QStyle::SP_MediaVolume));
}

//void Widget::on_pushButtonPrev_clicked()
//{
//	m_playlist->previous();
//}

//void Widget::on_pushButtonNext_clicked()
//{
//	m_playlist->next();
//}

void Widget::on_checkBoxLoop_stateChanged(int arg1)
{
	m_playlist->setPlaybackMode(QMediaPlaylist::PlaybackMode::Sequential);
	if(ui->checkBoxLoop->checkState())m_playlist->setPlaybackMode(QMediaPlaylist::PlaybackMode::Loop);
	if(ui->checkBoxShuffle->checkState())m_playlist->setPlaybackMode(QMediaPlaylist::PlaybackMode::Random);
}

void Widget::on_checkBoxShuffle_stateChanged(int arg1)
{
	m_playlist->setPlaybackMode(QMediaPlaylist::PlaybackMode::Sequential);
	if(ui->checkBoxLoop->checkState())m_playlist->setPlaybackMode(QMediaPlaylist::PlaybackMode::Loop);
	if(ui->checkBoxShuffle->checkState())m_playlist->setPlaybackMode(QMediaPlaylist::PlaybackMode::Random);
}
