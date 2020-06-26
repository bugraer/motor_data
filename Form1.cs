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
using System.IO.Ports;

namespace grafik
{

    public partial class Form1 : Form
    {

        int maksmh = 20, minmh = 0;
        int maksma = 20, minma = 0;
        int maksmt = 20, minmt = 0;
        int maksmg = 20, minmg = 0;
        int maksmc = 20, minmc = 0;
        string hiz, akim;
        
       double hiz1, akim1, w, GirisG, voltaj, tork, direnc,CikisG, kayip;

        
            
        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
           
        }

        public Form1()
        {

            

            InitializeComponent();
            serialPort1.PortName = comboBox1.Text; ;
            serialPort1.BaudRate = 9600;

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
           
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            comboBox1.Items.Add("COM1");
            comboBox1.Items.Add("COM2");
            comboBox1.Items.Add("COM3");
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            chart1.ChartAreas[0].AxisX.Minimum = minmh;
            chart1.ChartAreas[0].AxisX.Maximum = maksmh;
            chart1.ChartAreas[0].AxisX.LineColor = Color.Green;
            chart1.ChartAreas[0].AxisY.LineColor = Color.Green;
            chart1.ChartAreas[0].AxisY.Minimum = 0;
            chart1.ChartAreas[0].AxisY.Maximum = 1200;
            chart1.ChartAreas[0].AxisX.ScaleView.Zoom(minmh, maksmh);

            chart1.ChartAreas[1].AxisX.Minimum = minma;
            chart1.ChartAreas[1].AxisX.Maximum = maksma;
            chart1.ChartAreas[1].AxisX.LineColor = Color.Blue;
            chart1.ChartAreas[1].AxisY.LineColor = Color.Blue;
            chart1.ChartAreas[1].AxisY.Minimum = 0;
            chart1.ChartAreas[1].AxisY.Maximum = 1200;
            chart1.ChartAreas[1].AxisX.ScaleView.Zoom(minma, maksma);

            chart1.ChartAreas[2].AxisX.Minimum = minmt;
            chart1.ChartAreas[2].AxisX.Maximum = maksmt;
            chart1.ChartAreas[2].AxisX.LineColor = Color.Yellow;
            chart1.ChartAreas[2].AxisY.LineColor = Color.Yellow;
            chart1.ChartAreas[2].AxisY.Minimum = 0;
            chart1.ChartAreas[2].AxisY.Maximum = 1200;
            chart1.ChartAreas[2].AxisX.ScaleView.Zoom(minmt, maksmt);

            serialPort1.Write("1");
            hiz = serialPort1.ReadLine();

            serialPort2.Write("2");
            akim = serialPort2.ReadLine();


            serialPort1.DiscardInBuffer();
            serialPort2.DiscardInBuffer();
            if (hiz != null)
            {
                label1.Text = hiz + "d/d"; //Labele yazdırıyoruz.     
                this.chart1.Series["Rpm"].Points.AddXY((minmh + maksmh) / 2, hiz);
                maksmh++;
                minmh++;

                label2.Text = akim + "A"; //Labele yazdırıyoruz.     
                this.chart1.Series["Akim"].Points.AddXY((minma + maksma) / 2, akim);
                maksma++;
                 minma++;

               

                akim1 = Convert.ToDouble(akim);
                hiz1 = Convert.ToDouble(hiz);
               
                 w = (hiz1 * 0.1047);
                GirisG = voltaj * akim1;
                kayip = direnc * akim1;
                
                CikisG = GirisG - kayip;

                tork = CikisG / w;

                label7.Text = GirisG + "W"; //Labele yazdırıyoruz.
                this.chart1.Series["GirisGücü"].Points.AddXY((minmg + maksmg) / 2, GirisG);
                maksmg++;
                minmg++;

                label8.Text = CikisG + "W"; //Labele yazdırıyoruz. 
                this.chart1.Series["CikisGücü"].Points.AddXY((minmc + maksmc) / 2, CikisG);
                maksmc++;
                minmc++;

                label3.Text = tork + "Nm"; //Labele yazdırıyoruz.     
                this.chart1.Series["tork"].Points.AddXY((minmt + maksmt) / 2, tork);
                maksmt++;
                minmt++;
                dataGridView1.Rows.Add(hiz1,akim1,tork,GirisG,CikisG);
            }


        }

        private void button2_Click(object sender, EventArgs e)
        {
            serialPort1.Close();
            serialPort2.Close();
            timer1.Stop();
            button1.Enabled = true;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            /*   serialPort1.Open();
               serialPort2.Open();
               timer1.Start();
               button1.Enabled = false;

              

             */
          

            dataGridView1.AllowUserToAddRows = true;
            voltaj = Convert.ToDouble(textBox1.Text);
            direnc = Convert.ToDouble(textBox2.Text);
            int i;
            progressBar1.Minimum = 0;
            progressBar1.Maximum = 1000;

            for (i = 0; i <= 1000; i++)
            {
                progressBar1.Value = i;
            }

        }

        private void chart1_Click(object sender, EventArgs e)
        {

        }
    }
}