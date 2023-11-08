using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsForms
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void timer1_Tick(object sender, EventArgs e)
		{
			//https://learn.microsoft.com/en-us/dotnet/standard/base-types/standard-date-and-time-format-strings
			//https://learn.microsoft.com/en-us/dotnet/standard/base-types/custom-date-and-time-format-strings
			label1.Text = DateTime.Now.ToString("hh:mm:ss tt");
			if (cbShowDate.Checked) label1.Text += $"\n{DateTime.Now.ToString("dd.MM.yyyy")}";
		}

		private void label1_DoubleClick(object sender, EventArgs e)
		{
			this.FormBorderStyle = FormBorderStyle.Sizable;
			this.TransparencyKey = Color.AliceBlue;
			this.ShowInTaskbar = true;
			this.cbShowDate.Visible = true;
		}
	}
}
