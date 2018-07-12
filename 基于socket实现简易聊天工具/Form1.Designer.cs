namespace test
{
    partial class ChatRoom
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ChatRoom));
            this.conBtn = new System.Windows.Forms.Button();
            this.disBtn = new System.Windows.Forms.Button();
            this.chatBox = new System.Windows.Forms.RichTextBox();
            this.inputBox = new System.Windows.Forms.TextBox();
            this.ipBox = new System.Windows.Forms.TextBox();
            this.portBox = new System.Windows.Forms.TextBox();
            this.ipLabel = new System.Windows.Forms.Label();
            this.portLabel = new System.Windows.Forms.Label();
            this.sendBtn = new System.Windows.Forms.Button();
            this.chatLabel = new System.Windows.Forms.Label();
            this.show_ip = new System.Windows.Forms.Label();
            this.show_port = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.nickName = new System.Windows.Forms.TextBox();
            this.nameLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // conBtn
            // 
            this.conBtn.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.conBtn.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.conBtn.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.conBtn.Font = new System.Drawing.Font("宋体", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.conBtn.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.conBtn.ImageKey = "(无)";
            this.conBtn.Location = new System.Drawing.Point(395, 256);
            this.conBtn.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.conBtn.Name = "conBtn";
            this.conBtn.Size = new System.Drawing.Size(56, 24);
            this.conBtn.TabIndex = 0;
            this.conBtn.Text = "连接";
            this.conBtn.UseVisualStyleBackColor = false;
            this.conBtn.Click += new System.EventHandler(this.button1_Click);
            // 
            // disBtn
            // 
            this.disBtn.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.disBtn.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.disBtn.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.disBtn.Font = new System.Drawing.Font("宋体", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.disBtn.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.disBtn.Location = new System.Drawing.Point(498, 256);
            this.disBtn.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.disBtn.Name = "disBtn";
            this.disBtn.Size = new System.Drawing.Size(56, 24);
            this.disBtn.TabIndex = 0;
            this.disBtn.Text = "断开";
            this.disBtn.UseVisualStyleBackColor = false;
            this.disBtn.Click += new System.EventHandler(this.disBtn_Click);
            // 
            // chatBox
            // 
            this.chatBox.BackColor = System.Drawing.Color.Snow;
            this.chatBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.chatBox.Font = new System.Drawing.Font("宋体", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.chatBox.ForeColor = System.Drawing.SystemColors.WindowText;
            this.chatBox.Location = new System.Drawing.Point(26, 58);
            this.chatBox.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.chatBox.Name = "chatBox";
            this.chatBox.ReadOnly = true;
            this.chatBox.Size = new System.Drawing.Size(340, 222);
            this.chatBox.TabIndex = 2;
            this.chatBox.Text = "";
            // 
            // inputBox
            // 
            this.inputBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.inputBox.Font = new System.Drawing.Font("宋体", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.inputBox.Location = new System.Drawing.Point(38, 309);
            this.inputBox.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.inputBox.Name = "inputBox";
            this.inputBox.Size = new System.Drawing.Size(236, 24);
            this.inputBox.TabIndex = 3;
            // 
            // ipBox
            // 
            this.ipBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.ipBox.Font = new System.Drawing.Font("宋体", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.ipBox.Location = new System.Drawing.Point(423, 37);
            this.ipBox.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.ipBox.Name = "ipBox";
            this.ipBox.Size = new System.Drawing.Size(106, 24);
            this.ipBox.TabIndex = 4;
            this.ipBox.TextChanged += new System.EventHandler(this.textBox2_TextChanged);
            // 
            // portBox
            // 
            this.portBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.portBox.Font = new System.Drawing.Font("宋体", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.portBox.Location = new System.Drawing.Point(423, 90);
            this.portBox.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.portBox.Name = "portBox";
            this.portBox.Size = new System.Drawing.Size(106, 24);
            this.portBox.TabIndex = 5;
            // 
            // ipLabel
            // 
            this.ipLabel.AutoSize = true;
            this.ipLabel.BackColor = System.Drawing.Color.Transparent;
            this.ipLabel.Font = new System.Drawing.Font("宋体", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.ipLabel.Location = new System.Drawing.Point(424, 18);
            this.ipLabel.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.ipLabel.Name = "ipLabel";
            this.ipLabel.Size = new System.Drawing.Size(57, 15);
            this.ipLabel.TabIndex = 6;
            this.ipLabel.Text = "IP地址";
            // 
            // portLabel
            // 
            this.portLabel.AutoSize = true;
            this.portLabel.BackColor = System.Drawing.Color.Transparent;
            this.portLabel.Font = new System.Drawing.Font("宋体", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.portLabel.Location = new System.Drawing.Point(424, 71);
            this.portLabel.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.portLabel.Name = "portLabel";
            this.portLabel.Size = new System.Drawing.Size(55, 15);
            this.portLabel.TabIndex = 7;
            this.portLabel.Text = "端口号";
            // 
            // sendBtn
            // 
            this.sendBtn.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.sendBtn.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.sendBtn.Font = new System.Drawing.Font("宋体", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.sendBtn.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.sendBtn.Location = new System.Drawing.Point(296, 308);
            this.sendBtn.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.sendBtn.Name = "sendBtn";
            this.sendBtn.Size = new System.Drawing.Size(56, 24);
            this.sendBtn.TabIndex = 0;
            this.sendBtn.Text = "发送";
            this.sendBtn.UseVisualStyleBackColor = false;
            this.sendBtn.Click += new System.EventHandler(this.sendBtn_Click);
            // 
            // chatLabel
            // 
            this.chatLabel.AutoSize = true;
            this.chatLabel.BackColor = System.Drawing.Color.Transparent;
            this.chatLabel.Font = new System.Drawing.Font("宋体", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.chatLabel.Location = new System.Drawing.Point(22, 24);
            this.chatLabel.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.chatLabel.Name = "chatLabel";
            this.chatLabel.Size = new System.Drawing.Size(71, 15);
            this.chatLabel.TabIndex = 9;
            this.chatLabel.Text = "消息记录";
            // 
            // show_ip
            // 
            this.show_ip.AutoSize = true;
            this.show_ip.BackColor = System.Drawing.Color.Transparent;
            this.show_ip.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.show_ip.Location = new System.Drawing.Point(402, 178);
            this.show_ip.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.show_ip.Name = "show_ip";
            this.show_ip.Size = new System.Drawing.Size(12, 12);
            this.show_ip.TabIndex = 10;
            this.show_ip.Text = ".";
            // 
            // show_port
            // 
            this.show_port.AutoSize = true;
            this.show_port.BackColor = System.Drawing.Color.Transparent;
            this.show_port.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.show_port.Location = new System.Drawing.Point(402, 214);
            this.show_port.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.show_port.Name = "show_port";
            this.show_port.Size = new System.Drawing.Size(12, 12);
            this.show_port.TabIndex = 11;
            this.show_port.Text = ".";
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.button1.Font = new System.Drawing.Font("宋体", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.button1.Location = new System.Drawing.Point(296, 18);
            this.button1.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(56, 24);
            this.button1.TabIndex = 12;
            this.button1.Text = "清屏";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // nickName
            // 
            this.nickName.Font = new System.Drawing.Font("宋体", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.nickName.Location = new System.Drawing.Point(423, 142);
            this.nickName.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.nickName.Name = "nickName";
            this.nickName.Size = new System.Drawing.Size(107, 24);
            this.nickName.TabIndex = 13;
            // 
            // nameLabel
            // 
            this.nameLabel.AutoSize = true;
            this.nameLabel.BackColor = System.Drawing.Color.Transparent;
            this.nameLabel.Font = new System.Drawing.Font("宋体", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.nameLabel.Location = new System.Drawing.Point(424, 124);
            this.nameLabel.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.nameLabel.Name = "nameLabel";
            this.nameLabel.Size = new System.Drawing.Size(39, 15);
            this.nameLabel.TabIndex = 14;
            this.nameLabel.Text = "昵称";
            // 
            // ChatRoom
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.MintCream;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(784, 461);
            this.Controls.Add(this.nameLabel);
            this.Controls.Add(this.nickName);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.show_port);
            this.Controls.Add(this.show_ip);
            this.Controls.Add(this.chatLabel);
            this.Controls.Add(this.sendBtn);
            this.Controls.Add(this.portLabel);
            this.Controls.Add(this.ipLabel);
            this.Controls.Add(this.portBox);
            this.Controls.Add(this.ipBox);
            this.Controls.Add(this.inputBox);
            this.Controls.Add(this.chatBox);
            this.Controls.Add(this.disBtn);
            this.Controls.Add(this.conBtn);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Name = "ChatRoom";
            this.Text = "ChatRoom";
            this.Load += new System.EventHandler(this.ChatRoom_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button conBtn;
        private System.Windows.Forms.Button disBtn;
        private System.Windows.Forms.RichTextBox chatBox;
        private System.Windows.Forms.TextBox inputBox;
        private System.Windows.Forms.TextBox ipBox;
        private System.Windows.Forms.TextBox portBox;
        private System.Windows.Forms.Label ipLabel;
        private System.Windows.Forms.Label portLabel;
        private System.Windows.Forms.Button sendBtn;
        private System.Windows.Forms.Label chatLabel;
        private System.Windows.Forms.Label show_ip;
        private System.Windows.Forms.Label show_port;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox nickName;
        private System.Windows.Forms.Label nameLabel;
    }
}

