namespace MapEditor
{
    partial class Form1
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
            this.panel1 = new System.Windows.Forms.Panel();
            this.Btn_Output = new System.Windows.Forms.Button();
            this.Btn_CreateMap = new System.Windows.Forms.Button();
            this.Txt_Height = new System.Windows.Forms.TextBox();
            this.Txt_Width = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.Flp_Title = new System.Windows.Forms.FlowLayoutPanel();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.label3 = new System.Windows.Forms.Label();
            this.Btn_Open = new System.Windows.Forms.Button();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.Btn_Output);
            this.panel1.Controls.Add(this.Btn_CreateMap);
            this.panel1.Controls.Add(this.Txt_Height);
            this.panel1.Controls.Add(this.Txt_Width);
            this.panel1.Controls.Add(this.label2);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Location = new System.Drawing.Point(12, 12);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(266, 166);
            this.panel1.TabIndex = 0;
            // 
            // Btn_Output
            // 
            this.Btn_Output.Location = new System.Drawing.Point(135, 119);
            this.Btn_Output.Name = "Btn_Output";
            this.Btn_Output.Size = new System.Drawing.Size(128, 44);
            this.Btn_Output.TabIndex = 4;
            this.Btn_Output.Text = "Output";
            this.Btn_Output.UseVisualStyleBackColor = true;
            this.Btn_Output.Click += new System.EventHandler(this.Btn_Output_Click);
            // 
            // Btn_CreateMap
            // 
            this.Btn_CreateMap.Location = new System.Drawing.Point(3, 119);
            this.Btn_CreateMap.Name = "Btn_CreateMap";
            this.Btn_CreateMap.Size = new System.Drawing.Size(118, 44);
            this.Btn_CreateMap.TabIndex = 2;
            this.Btn_CreateMap.Text = "Create Map";
            this.Btn_CreateMap.UseVisualStyleBackColor = true;
            this.Btn_CreateMap.Click += new System.EventHandler(this.Btn_CreateMap_Click);
            // 
            // Txt_Height
            // 
            this.Txt_Height.Location = new System.Drawing.Point(126, 74);
            this.Txt_Height.Name = "Txt_Height";
            this.Txt_Height.Size = new System.Drawing.Size(100, 22);
            this.Txt_Height.TabIndex = 1;
            this.Txt_Height.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.Txt_Height_KeyPress);
            // 
            // Txt_Width
            // 
            this.Txt_Width.Location = new System.Drawing.Point(126, 31);
            this.Txt_Width.Name = "Txt_Width";
            this.Txt_Width.Size = new System.Drawing.Size(100, 22);
            this.Txt_Width.TabIndex = 1;
            this.Txt_Width.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.Txt_Width_KeyPress);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(27, 79);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(76, 17);
            this.label2.TabIndex = 0;
            this.label2.Text = "Tile Height";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(27, 31);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(71, 17);
            this.label1.TabIndex = 0;
            this.label1.Text = "Tile Width";
            // 
            // Flp_Title
            // 
            this.Flp_Title.AutoScroll = true;
            this.Flp_Title.Location = new System.Drawing.Point(12, 201);
            this.Flp_Title.Name = "Flp_Title";
            this.Flp_Title.Size = new System.Drawing.Size(266, 334);
            this.Flp_Title.TabIndex = 1;
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(284, 12);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(665, 397);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 2;
            this.pictureBox1.TabStop = false;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 181);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(56, 17);
            this.label3.TabIndex = 3;
            this.label3.Text = "TitleSet";
            // 
            // Btn_Open
            // 
            this.Btn_Open.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Btn_Open.ForeColor = System.Drawing.Color.DarkBlue;
            this.Btn_Open.Location = new System.Drawing.Point(503, 468);
            this.Btn_Open.Name = "Btn_Open";
            this.Btn_Open.Size = new System.Drawing.Size(213, 67);
            this.Btn_Open.TabIndex = 4;
            this.Btn_Open.Text = "Open Image";
            this.Btn_Open.UseVisualStyleBackColor = true;
            this.Btn_Open.Click += new System.EventHandler(this.Btn_Open_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(961, 548);
            this.Controls.Add(this.Btn_Open);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.Flp_Title);
            this.Controls.Add(this.panel1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form1_FormClosed);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button Btn_CreateMap;
        private System.Windows.Forms.TextBox Txt_Height;
        private System.Windows.Forms.TextBox Txt_Width;
        private System.Windows.Forms.FlowLayoutPanel Flp_Title;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button Btn_Output;
        private System.Windows.Forms.Button Btn_Open;
    }
}

