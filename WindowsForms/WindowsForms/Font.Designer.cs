namespace WindowsForms
{
	partial class Font
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.cbFont = new System.Windows.Forms.ComboBox();
			this.btnOK = new System.Windows.Forms.Button();
			this.btnCancel = new System.Windows.Forms.Button();
			this.lblExample = new System.Windows.Forms.Label();
			this.numericUpDownFontSize = new System.Windows.Forms.NumericUpDown();
			((System.ComponentModel.ISupportInitialize)(this.numericUpDownFontSize)).BeginInit();
			this.SuspendLayout();
			// 
			// cbFont
			// 
			this.cbFont.FormattingEnabled = true;
			this.cbFont.Location = new System.Drawing.Point(12, 12);
			this.cbFont.Name = "cbFont";
			this.cbFont.Size = new System.Drawing.Size(352, 21);
			this.cbFont.TabIndex = 0;
			this.cbFont.SelectionChangeCommitted += new System.EventHandler(this.comboBox1_SelectionChangeCommitted);
			// 
			// btnOK
			// 
			this.btnOK.Location = new System.Drawing.Point(209, 108);
			this.btnOK.Name = "btnOK";
			this.btnOK.Size = new System.Drawing.Size(75, 23);
			this.btnOK.TabIndex = 1;
			this.btnOK.Text = "OK";
			this.btnOK.UseVisualStyleBackColor = true;
			this.btnOK.Click += new System.EventHandler(this.btnOK_Click);
			// 
			// btnCancel
			// 
			this.btnCancel.Location = new System.Drawing.Point(290, 108);
			this.btnCancel.Name = "btnCancel";
			this.btnCancel.Size = new System.Drawing.Size(75, 23);
			this.btnCancel.TabIndex = 2;
			this.btnCancel.Text = "Отмена";
			this.btnCancel.UseVisualStyleBackColor = true;
			this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
			// 
			// lblExample
			// 
			this.lblExample.AutoSize = true;
			this.lblExample.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.lblExample.Location = new System.Drawing.Point(13, 55);
			this.lblExample.Name = "lblExample";
			this.lblExample.Size = new System.Drawing.Size(140, 37);
			this.lblExample.TabIndex = 3;
			this.lblExample.Text = "Example";
			// 
			// numericUpDownFontSize
			// 
			this.numericUpDownFontSize.Location = new System.Drawing.Point(320, 55);
			this.numericUpDownFontSize.Name = "numericUpDownFontSize";
			this.numericUpDownFontSize.Size = new System.Drawing.Size(44, 20);
			this.numericUpDownFontSize.TabIndex = 4;
			// 
			// Font
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(376, 143);
			this.Controls.Add(this.numericUpDownFontSize);
			this.Controls.Add(this.lblExample);
			this.Controls.Add(this.btnCancel);
			this.Controls.Add(this.btnOK);
			this.Controls.Add(this.cbFont);
			this.Name = "Font";
			this.Text = "Font";
			((System.ComponentModel.ISupportInitialize)(this.numericUpDownFontSize)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.ComboBox cbFont;
		private System.Windows.Forms.Button btnOK;
		private System.Windows.Forms.Button btnCancel;
		private System.Windows.Forms.Label lblExample;
		private System.Windows.Forms.NumericUpDown numericUpDownFontSize;
	}
}