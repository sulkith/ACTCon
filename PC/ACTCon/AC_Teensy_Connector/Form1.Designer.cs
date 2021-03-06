﻿namespace AC_Teensy_Connector
{
    partial class Form1
    {
        /// <summary>
        /// Erforderliche Designervariable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Verwendete Ressourcen bereinigen.
        /// </summary>
        /// <param name="disposing">True, wenn verwaltete Ressourcen gelöscht werden sollen; andernfalls False.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Vom Windows Form-Designer generierter Code

        /// <summary>
        /// Erforderliche Methode für die Designerunterstützung.
        /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.AC_Connection = new System.Windows.Forms.GroupBox();
            this.ACState = new System.Windows.Forms.Label();
            this.AC_Disconnect = new System.Windows.Forms.Button();
            this.AC_Connect = new System.Windows.Forms.Button();
            this.ACautoConnect = new System.Windows.Forms.CheckBox();
            this.label1 = new System.Windows.Forms.Label();
            this.ServerIP = new System.Windows.Forms.TextBox();
            this.Teensy_Connection = new System.Windows.Forms.GroupBox();
            this.TeensyState = new System.Windows.Forms.Label();
            this.TeensyDisconnect = new System.Windows.Forms.Button();
            this.TeensyConnect = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.Teensy_AutoConnect = new System.Windows.Forms.CheckBox();
            this.TeensyPort = new System.Windows.Forms.ComboBox();
            this.RefreshGui = new System.Windows.Forms.Timer(this.components);
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.maxRPM = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.TeensyFFOffs = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.TControl = new System.Windows.Forms.Label();
            this.ABS = new System.Windows.Forms.Label();
            this.Gear = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.rpm2 = new System.Windows.Forms.Label();
            this.rpm1 = new System.Windows.Forms.Label();
            this.SteerMark = new System.Windows.Forms.Label();
            this.Steering = new System.Windows.Forms.Label();
            this.CAR = new System.Windows.Forms.TextBox();
            this.Driver = new System.Windows.Forms.TextBox();
            this.Track = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.Brake = new System.Windows.Forms.ProgressBar();
            this.label6 = new System.Windows.Forms.Label();
            this.Throttlelabel = new System.Windows.Forms.Label();
            this.Throttle = new System.Windows.Forms.ProgressBar();
            this.WheelHR = new System.Windows.Forms.Label();
            this.WheelHL = new System.Windows.Forms.Label();
            this.WheelVR = new System.Windows.Forms.Label();
            this.WheelVL = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.checkACConnection = new System.Windows.Forms.Timer(this.components);
            this.AutoConnectTimer = new System.Windows.Forms.Timer(this.components);
            this.ReceiveAC = new System.Windows.Forms.Timer(this.components);
            this.AdditionalInfo = new System.Windows.Forms.TextBox();
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.AC_Connection.SuspendLayout();
            this.Teensy_Connection.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // AC_Connection
            // 
            this.AC_Connection.Controls.Add(this.ACState);
            this.AC_Connection.Controls.Add(this.AC_Disconnect);
            this.AC_Connection.Controls.Add(this.AC_Connect);
            this.AC_Connection.Controls.Add(this.ACautoConnect);
            this.AC_Connection.Controls.Add(this.label1);
            this.AC_Connection.Controls.Add(this.ServerIP);
            this.AC_Connection.Location = new System.Drawing.Point(9, 10);
            this.AC_Connection.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.AC_Connection.Name = "AC_Connection";
            this.AC_Connection.Padding = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.AC_Connection.Size = new System.Drawing.Size(154, 110);
            this.AC_Connection.TabIndex = 0;
            this.AC_Connection.TabStop = false;
            this.AC_Connection.Text = "AC Connection";
            // 
            // ACState
            // 
            this.ACState.BackColor = System.Drawing.Color.Red;
            this.ACState.Location = new System.Drawing.Point(4, 87);
            this.ACState.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.ACState.Name = "ACState";
            this.ACState.Size = new System.Drawing.Size(146, 16);
            this.ACState.TabIndex = 8;
            this.ACState.Text = "NotConnected";
            this.ACState.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // AC_Disconnect
            // 
            this.AC_Disconnect.Location = new System.Drawing.Point(76, 66);
            this.AC_Disconnect.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.AC_Disconnect.Name = "AC_Disconnect";
            this.AC_Disconnect.Size = new System.Drawing.Size(75, 19);
            this.AC_Disconnect.TabIndex = 4;
            this.AC_Disconnect.Text = "Disconnect";
            this.AC_Disconnect.UseVisualStyleBackColor = true;
            this.AC_Disconnect.Click += new System.EventHandler(this.AC_Disconnect_Click);
            // 
            // AC_Connect
            // 
            this.AC_Connect.Location = new System.Drawing.Point(4, 66);
            this.AC_Connect.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.AC_Connect.Name = "AC_Connect";
            this.AC_Connect.Size = new System.Drawing.Size(67, 19);
            this.AC_Connect.TabIndex = 3;
            this.AC_Connect.Text = "Connect";
            this.AC_Connect.UseVisualStyleBackColor = true;
            this.AC_Connect.Click += new System.EventHandler(this.AC_Connect_Click);
            // 
            // ACautoConnect
            // 
            this.ACautoConnect.AutoSize = true;
            this.ACautoConnect.Checked = true;
            this.ACautoConnect.CheckState = System.Windows.Forms.CheckState.Checked;
            this.ACautoConnect.Location = new System.Drawing.Point(64, 44);
            this.ACautoConnect.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.ACautoConnect.Name = "ACautoConnect";
            this.ACautoConnect.Size = new System.Drawing.Size(88, 17);
            this.ACautoConnect.TabIndex = 2;
            this.ACautoConnect.Text = "AutoConnect";
            this.ACautoConnect.UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(4, 21);
            this.label1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(55, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "AC-Server";
            // 
            // ServerIP
            // 
            this.ServerIP.Location = new System.Drawing.Point(64, 21);
            this.ServerIP.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.ServerIP.Name = "ServerIP";
            this.ServerIP.Size = new System.Drawing.Size(88, 20);
            this.ServerIP.TabIndex = 0;
            this.ServerIP.Text = "127.0.0.1";
            this.ServerIP.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // Teensy_Connection
            // 
            this.Teensy_Connection.Controls.Add(this.TeensyState);
            this.Teensy_Connection.Controls.Add(this.TeensyDisconnect);
            this.Teensy_Connection.Controls.Add(this.TeensyConnect);
            this.Teensy_Connection.Controls.Add(this.label2);
            this.Teensy_Connection.Controls.Add(this.Teensy_AutoConnect);
            this.Teensy_Connection.Controls.Add(this.TeensyPort);
            this.Teensy_Connection.Location = new System.Drawing.Point(167, 10);
            this.Teensy_Connection.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Teensy_Connection.Name = "Teensy_Connection";
            this.Teensy_Connection.Padding = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Teensy_Connection.Size = new System.Drawing.Size(160, 110);
            this.Teensy_Connection.TabIndex = 1;
            this.Teensy_Connection.TabStop = false;
            this.Teensy_Connection.Text = "Teensy Connection";
            // 
            // TeensyState
            // 
            this.TeensyState.BackColor = System.Drawing.Color.Red;
            this.TeensyState.Location = new System.Drawing.Point(4, 87);
            this.TeensyState.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.TeensyState.Name = "TeensyState";
            this.TeensyState.Size = new System.Drawing.Size(146, 16);
            this.TeensyState.TabIndex = 7;
            this.TeensyState.Text = "NotConnected";
            this.TeensyState.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.TeensyState.Click += new System.EventHandler(this.label3_Click);
            // 
            // TeensyDisconnect
            // 
            this.TeensyDisconnect.Location = new System.Drawing.Point(76, 66);
            this.TeensyDisconnect.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.TeensyDisconnect.Name = "TeensyDisconnect";
            this.TeensyDisconnect.Size = new System.Drawing.Size(75, 19);
            this.TeensyDisconnect.TabIndex = 6;
            this.TeensyDisconnect.Text = "Disconnect";
            this.TeensyDisconnect.UseVisualStyleBackColor = true;
            this.TeensyDisconnect.Click += new System.EventHandler(this.button1_Click);
            // 
            // TeensyConnect
            // 
            this.TeensyConnect.Location = new System.Drawing.Point(4, 66);
            this.TeensyConnect.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.TeensyConnect.Name = "TeensyConnect";
            this.TeensyConnect.Size = new System.Drawing.Size(67, 19);
            this.TeensyConnect.TabIndex = 5;
            this.TeensyConnect.Text = "Connect";
            this.TeensyConnect.UseVisualStyleBackColor = true;
            this.TeensyConnect.Click += new System.EventHandler(this.button2_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(4, 21);
            this.label2.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(58, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Serial Port ";
            // 
            // Teensy_AutoConnect
            // 
            this.Teensy_AutoConnect.AutoSize = true;
            this.Teensy_AutoConnect.Checked = true;
            this.Teensy_AutoConnect.CheckState = System.Windows.Forms.CheckState.Checked;
            this.Teensy_AutoConnect.Location = new System.Drawing.Point(68, 44);
            this.Teensy_AutoConnect.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Teensy_AutoConnect.Name = "Teensy_AutoConnect";
            this.Teensy_AutoConnect.Size = new System.Drawing.Size(88, 17);
            this.Teensy_AutoConnect.TabIndex = 1;
            this.Teensy_AutoConnect.Text = "AutoConnect";
            this.Teensy_AutoConnect.UseVisualStyleBackColor = true;
            this.Teensy_AutoConnect.CheckedChanged += new System.EventHandler(this.Teensy_AutoConnect_CheckedChanged);
            // 
            // TeensyPort
            // 
            this.TeensyPort.FormattingEnabled = true;
            this.TeensyPort.Items.AddRange(new object[] {
            "COM1",
            "COM2",
            "COM3",
            "COM4",
            "COM5",
            "COM6",
            "COM7"});
            this.TeensyPort.Location = new System.Drawing.Point(68, 21);
            this.TeensyPort.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.TeensyPort.Name = "TeensyPort";
            this.TeensyPort.Size = new System.Drawing.Size(84, 21);
            this.TeensyPort.TabIndex = 0;
            this.TeensyPort.Text = "COM4";
            this.TeensyPort.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // RefreshGui
            // 
            this.RefreshGui.Enabled = true;
            this.RefreshGui.Interval = 50;
            this.RefreshGui.Tick += new System.EventHandler(this.RefreshGui_Tick);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.maxRPM);
            this.groupBox1.Controls.Add(this.label10);
            this.groupBox1.Controls.Add(this.TeensyFFOffs);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Location = new System.Drawing.Point(9, 124);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.groupBox1.Size = new System.Drawing.Size(320, 60);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Settings";
            // 
            // maxRPM
            // 
            this.maxRPM.Location = new System.Drawing.Point(111, 35);
            this.maxRPM.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.maxRPM.Name = "maxRPM";
            this.maxRPM.Size = new System.Drawing.Size(44, 20);
            this.maxRPM.TabIndex = 3;
            this.maxRPM.Text = "7000";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(4, 37);
            this.label10.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(53, 13);
            this.label10.TabIndex = 2;
            this.label10.Text = "max RPM";
            // 
            // TeensyFFOffs
            // 
            this.TeensyFFOffs.Location = new System.Drawing.Point(111, 12);
            this.TeensyFFOffs.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.TeensyFFOffs.Name = "TeensyFFOffs";
            this.TeensyFFOffs.Size = new System.Drawing.Size(44, 20);
            this.TeensyFFOffs.TabIndex = 1;
            this.TeensyFFOffs.Text = "2500";
            this.TeensyFFOffs.TextChanged += new System.EventHandler(this.textBox1_TextChanged_1);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(4, 15);
            this.label3.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(103, 13);
            this.label3.TabIndex = 0;
            this.label3.Text = "Sliding Wheel Offset";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.TControl);
            this.groupBox2.Controls.Add(this.ABS);
            this.groupBox2.Controls.Add(this.Gear);
            this.groupBox2.Controls.Add(this.label11);
            this.groupBox2.Controls.Add(this.rpm2);
            this.groupBox2.Controls.Add(this.rpm1);
            this.groupBox2.Controls.Add(this.SteerMark);
            this.groupBox2.Controls.Add(this.Steering);
            this.groupBox2.Controls.Add(this.CAR);
            this.groupBox2.Controls.Add(this.Driver);
            this.groupBox2.Controls.Add(this.Track);
            this.groupBox2.Controls.Add(this.label9);
            this.groupBox2.Controls.Add(this.label8);
            this.groupBox2.Controls.Add(this.label7);
            this.groupBox2.Controls.Add(this.Brake);
            this.groupBox2.Controls.Add(this.label6);
            this.groupBox2.Controls.Add(this.Throttlelabel);
            this.groupBox2.Controls.Add(this.Throttle);
            this.groupBox2.Controls.Add(this.WheelHR);
            this.groupBox2.Controls.Add(this.WheelHL);
            this.groupBox2.Controls.Add(this.WheelVR);
            this.groupBox2.Controls.Add(this.WheelVL);
            this.groupBox2.Controls.Add(this.label4);
            this.groupBox2.Controls.Add(this.label5);
            this.groupBox2.Location = new System.Drawing.Point(9, 189);
            this.groupBox2.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Padding = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.groupBox2.Size = new System.Drawing.Size(319, 219);
            this.groupBox2.TabIndex = 3;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "AC Data";
            // 
            // TControl
            // 
            this.TControl.BackColor = System.Drawing.Color.Red;
            this.TControl.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TControl.Location = new System.Drawing.Point(76, 176);
            this.TControl.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.TControl.Name = "TControl";
            this.TControl.Size = new System.Drawing.Size(67, 37);
            this.TControl.TabIndex = 23;
            this.TControl.Text = "TC";
            this.TControl.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.TControl.Click += new System.EventHandler(this.TControl_Click);
            // 
            // ABS
            // 
            this.ABS.BackColor = System.Drawing.Color.Red;
            this.ABS.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ABS.Location = new System.Drawing.Point(5, 176);
            this.ABS.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.ABS.Name = "ABS";
            this.ABS.Size = new System.Drawing.Size(66, 37);
            this.ABS.TabIndex = 22;
            this.ABS.Text = "ABS";
            this.ABS.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Gear
            // 
            this.Gear.Font = new System.Drawing.Font("Microsoft Sans Serif", 19.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Gear.Location = new System.Drawing.Point(284, 176);
            this.Gear.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Gear.Name = "Gear";
            this.Gear.Size = new System.Drawing.Size(32, 37);
            this.Gear.TabIndex = 21;
            this.Gear.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(249, 176);
            this.label11.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(30, 13);
            this.label11.TabIndex = 20;
            this.label11.Text = "Gear";
            // 
            // rpm2
            // 
            this.rpm2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(0)))));
            this.rpm2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rpm2.ForeColor = System.Drawing.Color.White;
            this.rpm2.Location = new System.Drawing.Point(34, 155);
            this.rpm2.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.rpm2.Name = "rpm2";
            this.rpm2.Size = new System.Drawing.Size(310, 19);
            this.rpm2.TabIndex = 19;
            // 
            // rpm1
            // 
            this.rpm1.BackColor = System.Drawing.Color.Black;
            this.rpm1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.rpm1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rpm1.ForeColor = System.Drawing.Color.White;
            this.rpm1.Location = new System.Drawing.Point(4, 155);
            this.rpm1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.rpm1.Name = "rpm1";
            this.rpm1.Size = new System.Drawing.Size(310, 19);
            this.rpm1.TabIndex = 18;
            // 
            // SteerMark
            // 
            this.SteerMark.BackColor = System.Drawing.Color.Black;
            this.SteerMark.Location = new System.Drawing.Point(120, 129);
            this.SteerMark.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.SteerMark.Name = "SteerMark";
            this.SteerMark.Size = new System.Drawing.Size(5, 19);
            this.SteerMark.TabIndex = 17;
            this.SteerMark.Text = "label11";
            // 
            // Steering
            // 
            this.Steering.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.Steering.Location = new System.Drawing.Point(4, 129);
            this.Steering.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.Steering.Name = "Steering";
            this.Steering.Size = new System.Drawing.Size(311, 19);
            this.Steering.TabIndex = 16;
            this.Steering.Text = "0°";
            this.Steering.Click += new System.EventHandler(this.label10_Click);
            // 
            // CAR
            // 
            this.CAR.Location = new System.Drawing.Point(52, 54);
            this.CAR.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.CAR.Name = "CAR";
            this.CAR.ReadOnly = true;
            this.CAR.Size = new System.Drawing.Size(196, 20);
            this.CAR.TabIndex = 15;
            // 
            // Driver
            // 
            this.Driver.Location = new System.Drawing.Point(52, 35);
            this.Driver.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Driver.Name = "Driver";
            this.Driver.ReadOnly = true;
            this.Driver.Size = new System.Drawing.Size(196, 20);
            this.Driver.TabIndex = 14;
            // 
            // Track
            // 
            this.Track.Location = new System.Drawing.Point(52, 16);
            this.Track.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Track.Name = "Track";
            this.Track.ReadOnly = true;
            this.Track.Size = new System.Drawing.Size(196, 20);
            this.Track.TabIndex = 13;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(4, 57);
            this.label9.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(26, 13);
            this.label9.TabIndex = 12;
            this.label9.Text = "Car:";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(4, 37);
            this.label8.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(38, 13);
            this.label8.TabIndex = 11;
            this.label8.Text = "Driver:";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(4, 19);
            this.label7.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(38, 13);
            this.label7.TabIndex = 10;
            this.label7.Text = "Track:";
            // 
            // Brake
            // 
            this.Brake.Enabled = false;
            this.Brake.Location = new System.Drawing.Point(52, 98);
            this.Brake.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Brake.MarqueeAnimationSpeed = 10;
            this.Brake.Name = "Brake";
            this.Brake.Size = new System.Drawing.Size(195, 19);
            this.Brake.Style = System.Windows.Forms.ProgressBarStyle.Continuous;
            this.Brake.TabIndex = 9;
            this.Brake.Value = 50;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(4, 98);
            this.label6.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(35, 13);
            this.label6.TabIndex = 8;
            this.label6.Text = "Brake";
            // 
            // Throttlelabel
            // 
            this.Throttlelabel.AutoSize = true;
            this.Throttlelabel.Location = new System.Drawing.Point(4, 75);
            this.Throttlelabel.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.Throttlelabel.Name = "Throttlelabel";
            this.Throttlelabel.Size = new System.Drawing.Size(43, 13);
            this.Throttlelabel.TabIndex = 7;
            this.Throttlelabel.Text = "Throttle";
            // 
            // Throttle
            // 
            this.Throttle.Location = new System.Drawing.Point(52, 75);
            this.Throttle.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Throttle.Name = "Throttle";
            this.Throttle.Size = new System.Drawing.Size(195, 19);
            this.Throttle.TabIndex = 6;
            this.Throttle.Value = 50;
            // 
            // WheelHR
            // 
            this.WheelHR.BackColor = System.Drawing.Color.Black;
            this.WheelHR.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.WheelHR.Location = new System.Drawing.Point(304, 98);
            this.WheelHR.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.WheelHR.Name = "WheelHR";
            this.WheelHR.Size = new System.Drawing.Size(11, 26);
            this.WheelHR.TabIndex = 5;
            this.WheelHR.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // WheelHL
            // 
            this.WheelHL.BackColor = System.Drawing.Color.Black;
            this.WheelHL.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.WheelHL.Location = new System.Drawing.Point(251, 98);
            this.WheelHL.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.WheelHL.Name = "WheelHL";
            this.WheelHL.Size = new System.Drawing.Size(11, 26);
            this.WheelHL.TabIndex = 4;
            this.WheelHL.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // WheelVR
            // 
            this.WheelVR.BackColor = System.Drawing.Color.Black;
            this.WheelVR.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.WheelVR.Location = new System.Drawing.Point(304, 25);
            this.WheelVR.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.WheelVR.Name = "WheelVR";
            this.WheelVR.Size = new System.Drawing.Size(11, 26);
            this.WheelVR.TabIndex = 3;
            this.WheelVR.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // WheelVL
            // 
            this.WheelVL.BackColor = System.Drawing.Color.Black;
            this.WheelVL.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.WheelVL.Location = new System.Drawing.Point(251, 25);
            this.WheelVL.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.WheelVL.Name = "WheelVL";
            this.WheelVL.Size = new System.Drawing.Size(11, 26);
            this.WheelVL.TabIndex = 2;
            this.WheelVL.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label4
            // 
            this.label4.BackColor = System.Drawing.Color.Blue;
            this.label4.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label4.ForeColor = System.Drawing.Color.White;
            this.label4.Location = new System.Drawing.Point(251, 51);
            this.label4.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(64, 60);
            this.label4.TabIndex = 0;
            this.label4.Text = "CAR";
            this.label4.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label5
            // 
            this.label5.BackColor = System.Drawing.Color.Blue;
            this.label5.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 22.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.Color.White;
            this.label5.Location = new System.Drawing.Point(251, 19);
            this.label5.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(64, 106);
            this.label5.TabIndex = 1;
            this.label5.Text = "^";
            this.label5.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // checkACConnection
            // 
            this.checkACConnection.Interval = 50;
            this.checkACConnection.Tick += new System.EventHandler(this.checkACConnection_Tick);
            // 
            // AutoConnectTimer
            // 
            this.AutoConnectTimer.Enabled = true;
            this.AutoConnectTimer.Interval = 500;
            this.AutoConnectTimer.Tick += new System.EventHandler(this.AutoConnectTimer_Tick);
            // 
            // ReceiveAC
            // 
            this.ReceiveAC.Interval = 1;
            this.ReceiveAC.Tick += new System.EventHandler(this.ReceiveAC_Tick);
            // 
            // AdditionalInfo
            // 
            this.AdditionalInfo.Location = new System.Drawing.Point(351, 10);
            this.AdditionalInfo.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.AdditionalInfo.Multiline = true;
            this.AdditionalInfo.Name = "AdditionalInfo";
            this.AdditionalInfo.Size = new System.Drawing.Size(366, 396);
            this.AdditionalInfo.TabIndex = 4;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(724, 414);
            this.Controls.Add(this.AdditionalInfo);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.Teensy_Connection);
            this.Controls.Add(this.AC_Connection);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Name = "Form1";
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.Text = "ACTCon";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.AC_Connection.ResumeLayout(false);
            this.AC_Connection.PerformLayout();
            this.Teensy_Connection.ResumeLayout(false);
            this.Teensy_Connection.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox AC_Connection;
        private System.Windows.Forms.TextBox ServerIP;
        private System.Windows.Forms.CheckBox ACautoConnect;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button AC_Disconnect;
        private System.Windows.Forms.Button AC_Connect;
        private System.Windows.Forms.GroupBox Teensy_Connection;
        private System.Windows.Forms.ComboBox TeensyPort;
        private System.Windows.Forms.Label TeensyState;
        private System.Windows.Forms.Button TeensyDisconnect;
        private System.Windows.Forms.Button TeensyConnect;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.CheckBox Teensy_AutoConnect;
        private System.Windows.Forms.Label ACState;
        private System.Windows.Forms.Timer RefreshGui;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox TeensyFFOffs;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label WheelHR;
        private System.Windows.Forms.Label WheelHL;
        private System.Windows.Forms.Label WheelVR;
        private System.Windows.Forms.Label WheelVL;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ProgressBar Brake;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label Throttlelabel;
        private System.Windows.Forms.ProgressBar Throttle;
        private System.Windows.Forms.TextBox CAR;
        private System.Windows.Forms.TextBox Driver;
        private System.Windows.Forms.TextBox Track;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label Steering;
        private System.Windows.Forms.Label SteerMark;
        private System.Windows.Forms.TextBox maxRPM;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label rpm2;
        private System.Windows.Forms.Label rpm1;
        private System.Windows.Forms.TextBox Gear;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label TControl;
        private System.Windows.Forms.Label ABS;
        private System.Windows.Forms.Timer checkACConnection;
        private System.Windows.Forms.Timer AutoConnectTimer;
        private System.Windows.Forms.Timer ReceiveAC;
        private System.Windows.Forms.TextBox AdditionalInfo;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
    }
}

