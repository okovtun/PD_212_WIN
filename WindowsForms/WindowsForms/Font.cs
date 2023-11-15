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
	public partial class Font : Form
	{
		public System.Drawing.Font NewFont	{ get; set; }
		public System.Drawing.Font OldFont	{ get; set; }
		public Font(System.Drawing.Font oldFont)
		{
			InitializeComponent();
			//MessageBox.Show(this, currectDirectory, "Current directory", MessageBoxButtons.OK);
			if(Directory.GetCurrentDirectory().Contains("bin"))Directory.SetCurrentDirectory("..\\..\\Fonts");
			string currectDirectory = Directory.GetCurrentDirectory();
			//MessageBox.Show(this, currectDirectory, "Current directory", MessageBoxButtons.OK);
			foreach (string i in Directory.GetFiles(currectDirectory))
			{
				if(i.Split('\\').Last().Contains(".ttf"))this.cbFont.Items.Add(i.Split('\\').Last());
			}
			OldFont = oldFont;
			numericUpDownFontSize.Value = (decimal)OldFont.Size;
			//MessageBox.Show(this, OldFont.Name, "Font", MessageBoxButtons.OK);
		}

		private void btnCancel_Click(object sender, EventArgs e)
		{
			this.Close();
		}

		private void btnOK_Click(object sender, EventArgs e)
		{
			OldFont = NewFont;
			this.Close();
		}

		private void comboBox1_SelectionChangeCommitted(object sender, EventArgs e)
		{
			PrivateFontCollection pfs = new PrivateFontCollection();
			pfs.AddFontFile(cbFont.SelectedItem.ToString());
			NewFont = new System.Drawing.Font(pfs.Families[0], (int)numericUpDownFontSize.Value);
			//NewFont = new System.Drawing.Font(pfs.Families[0], lblExample.Font.Size);
			lblExample.Font = NewFont;
		}
	}
}
