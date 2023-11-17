using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Drawing.Text;

namespace WindowsForms
{
	public partial class Form1 : Form
	{
		string font_file;
		int size;
		Color foreground;
		Color background;
		bool show_date;
		bool visible_controls;
		WindowsForms.Font choose_font;

		public Form1()
		{
			InitializeComponent();
			this.Location = new System.Drawing.Point
				(
				System.Windows.Forms.Screen.PrimaryScreen.Bounds.Right - this.Width - 50,
				System.Windows.Forms.Screen.PrimaryScreen.Bounds.Top + 100
				);
			show_date = false;
			visible_controls = false;
			btnHideControls.Visible = false;
			btnClose.Visible = false;

			choose_font = new WindowsForms.Font(label1.Font);

			font_file = "";
			LoadSettings();
		}
		public void SaveSettings()
		{
			StreamWriter sw = new StreamWriter("Settings.cfg");
			sw.WriteLine(font_file);
			sw.WriteLine(label1.Font.Size);
			sw.WriteLine(label1.ForeColor.ToArgb());
			sw.WriteLine(label1.BackColor.ToArgb());
			sw.Close();
		}
		public void LoadSettings()
		{
			//MessageBox.Show(this, Directory.GetCurrentDirectory(), "Directory", MessageBoxButtons.OK);
			StreamReader sr = new StreamReader("Settings.cfg");
			font_file = sr.ReadLine();
			size = Convert.ToInt32(sr.ReadLine());
			foreground = Color.FromArgb(Convert.ToInt32(sr.ReadLine()));
			background = Color.FromArgb(Convert.ToInt32(sr.ReadLine()));
			sr.Close();

			PrivateFontCollection pfc = new PrivateFontCollection();
			pfc.AddFontFile(font_file);
			System.Drawing.Font font = new System.Drawing.Font(pfc.Families[0], size);
			label1.Font = font;
			label1.ForeColor = foreground;
			label1.BackColor = background;
		}
		private void SetShowDate(bool show_date)
		{
			this.show_date = show_date;
			cbShowDate.Checked = show_date;
			showDateToolStripMenuItem.Checked = show_date;
		}
		private void SetControlsVisibility(bool visible_controls)
		{
			this.visible_controls = visible_controls;
			this.FormBorderStyle = visible_controls ? FormBorderStyle.Sizable : FormBorderStyle.None;
			this.TransparencyKey = visible_controls ? Color.AliceBlue : SystemColors.Control;

			this.ShowInTaskbar = visible_controls;
			this.cbShowDate.Visible = visible_controls;

			this.btnFont.Visible = visible_controls;
			this.btnHideControls.Visible = visible_controls;
			this.btnClose.Visible = visible_controls;
			//this.notifyIcon1.Visible = !visible_controls;

			this.showControlsToolStripMenuItem.Checked = visible_controls;
		}
		private void timer1_Tick(object sender, EventArgs e)
		{
			//https://learn.microsoft.com/en-us/dotnet/standard/base-types/standard-date-and-time-format-strings
			//https://learn.microsoft.com/en-us/dotnet/standard/base-types/custom-date-and-time-format-strings
			label1.Text = DateTime.Now.ToString("hh:mm:ss tt");
			if (cbShowDate.Checked) label1.Text += $"\n{DateTime.Now.ToString("dd.MM.yyyy")}";
			notifyIcon1.Text = DateTime.Now.ToString("hh:mm:ss tt");
		}

		private void label1_DoubleClick(object sender, EventArgs e)
		{
			//this.FormBorderStyle = FormBorderStyle.Sizable;
			//this.TransparencyKey = Color.AliceBlue;
			//this.ShowInTaskbar = true;
			//this.cbShowDate.Visible = true;
			//this.btnHideControls.Visible = true;
			//this.btnClose.Visible = true;
			//this.notifyIcon1.Visible = false;
			SetControlsVisibility(true);
		}

		private void btnHideControls_Click(object sender, EventArgs e)
		{
			//this.FormBorderStyle = FormBorderStyle.None;
			//this.TransparencyKey = SystemColors.Control;
			//this.ShowInTaskbar = false;
			//this.cbShowDate.Visible = false;
			//this.btnHideControls.Visible = false;
			//this.btnClose.Visible = false;
			//this.notifyIcon1.Visible = true;
			SetControlsVisibility(false);
		}

		private void btnClose_Click(object sender, EventArgs e)
		{
			SaveSettings();
			this.Close();
		}

		private void closeToolStripMenuItem_Click(object sender, EventArgs e)
		{
			SaveSettings();
			this.Close();
		}

		private void showDateToolStripMenuItem_Click(object sender, EventArgs e)
		{
			this.show_date = showDateToolStripMenuItem.Checked;
			SetShowDate(show_date);
		}

		private void showControlsToolStripMenuItem_Click(object sender, EventArgs e)
		{
			if (showControlsToolStripMenuItem.Checked) label1_DoubleClick(sender, e);
			else btnHideControls_Click(sender, e);
		}

		private void cbShowDate_CheckedChanged(object sender, EventArgs e)
		{
			SetShowDate(cbShowDate.Checked);
		}

		private void notifyIcon1_MouseDoubleClick(object sender, MouseEventArgs e)
		{
			label1_DoubleClick(sender, e);
		}

		private void btnFont_Click(object sender, EventArgs e)
		{
			//Font font = new Font(label1.Font);
			DialogResult result = choose_font.ShowDialog(this);
			if (result == DialogResult.OK)
			{
				label1.Font = choose_font.OldFont;
				font_file = choose_font.FontFile;
			}
		}

		private void foregroundToolStripMenuItem_Click(object sender, EventArgs e)
		{
			colorDialog1.ShowDialog(this);
			label1.ForeColor = colorDialog1.Color;
		}

		private void backgroundToolStripMenuItem_Click(object sender, EventArgs e)
		{
			colorDialog1.ShowDialog(this);
			label1.BackColor = colorDialog1.Color;
		}

		private void toolStripMenuItemFont_Click(object sender, EventArgs e)
		{
			btnFont_Click(sender, e);
		}
	}
}
