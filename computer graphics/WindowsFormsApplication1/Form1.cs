using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Image_Browser
{
    public partial class Form1 : Form
    {
        Bitmap img;
        public Form1()
        {
            InitializeComponent();
        }
        //
        // для Lab
        //
        double f(double x)
        {
            double coef = 1.0 / 3.0;
            if (x < 0.008856) return (7.787 * x + (double)16 / (double)116);
            else return System.Math.Pow(x, coef);

        }
        //
        // Открытие файла
        //
        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            label13.Visible = true;
            OpenFileDialog of = new OpenFileDialog();
            of.Filter = "JPeg Image|*.jpg|Bitmap Image|*.bmp|Gif Image|*.gif";
            if (of.ShowDialog() == DialogResult.OK)
            {
                if (of.FileName != null)
                {
                    img = new Bitmap(of.FileName);
                    pictureBox1.Image = img;
                    pictureBox1.Refresh();
                }
            }
        }
        //
        // Сохранение файла
        //
        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveFileDialog sf = new SaveFileDialog();
            sf.Filter = "JPeg Image|*.jpg|Bitmap Image|*.bmp|Gif Image|*.gif";
            if (pictureBox1.Image != null)
            {
                if (sf.ShowDialog() == DialogResult.OK)
                {
                    if (sf.FileName != null)
                    {
                        img = new Bitmap(pictureBox1.Image);
                        img.Save(sf.FileName);
                    }
                }
            }
            else return;
        }
        //
        // Инвертирование цветов
        //
        private void invertColorsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                Bitmap res = new Bitmap(img);
                for (int i = 0; i < res.Width; ++i)
                    for (int j = 0; j < res.Height; ++j)
                    {
                        Color c = res.GetPixel(i, j);
                        res.SetPixel(i, j, Color.FromArgb(255 - c.R, 255 - c.G, 255 - c.B));
                    }
                pictureBox1.Image = res;
                pictureBox1.Refresh();
            }
            else return;
        }
        //
        // Перевод в ч/б
        //
        private void blackandwhiteImageToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                Bitmap res = new Bitmap(img);
                int rgb;
             
                    for (int i = 0; i < res.Width; ++i)
                        for (int j = 0; j < res.Height; ++j)
                        {
                            Color c = res.GetPixel(i, j);
                            rgb = (c.R + c.G + c.B) / 3;
                            res.SetPixel(i, j, rgb <= 127 ? Color.Black : Color.White);
                        }
                    pictureBox1.Image = res;
                    pictureBox1.Refresh();
             
            }
            else return;
        }
        //
        // Перевод в оттенки серого по интенсивности(стандарт CIE)
        //
        private void grayscaleIntensityToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                Bitmap res = new Bitmap(img);
                int Y;
                for (int i = 0; i < res.Width; ++i)
                    for (int j = 0; j < res.Height; ++j)
                    {
                        Color c = res.GetPixel(i, j);
                        Y = (int)(0.213 * c.R + 0.715 * c.G + 0.072 * c.B);
                        res.SetPixel(i, j, Color.FromArgb(Y, Y, Y));
                    }
                pictureBox1.Image = res;
                pictureBox1.Refresh();
            }
            else return;
        }
        //
        // Перевод в модель Lab
        //
        private void labToolStripMenuItem_Click(object sender, EventArgs e)
        {
            double coef = 1 / 3, R, G, B, L, a, b, X, Y, Z, Xn = 255 * (0.412 + 0.358 + 0.18), Yn = 255 * (0.213 + 0.715 + 0.072), Zn = 255 * (0.019 + 0.119 + 0.95);
            if (pictureBox1.Image != null)
            {
                label14.Text = "L:";
                label15.Text = "a:";
                label16.Text = "b:";

                Bitmap res2 = new Bitmap(img);
                Bitmap res3 = new Bitmap(img);
                Bitmap res4 = new Bitmap(img);
                for (int i = 0; i < res2.Width; ++i)
                    for (int j = 0; j < res2.Height; ++j)
                    {
                        Color c = res2.GetPixel(i, j);
                        X = (0.412 * c.R + 0.358 * c.G + 0.18 * c.B) / Xn;
                        Y = (0.213 * c.R + 0.715 * c.G + 0.072 * c.B) / Yn;
                        Z = (0.019 * c.R + 0.119 * c.G + 0.95 * c.B) / Zn;
                        L = 116 * f(Y) - 16;
                        a = 500 * (f(X) - f(Y));
                        b = 200 * (f(Y) - f(Z));

                        
                        double F = (L + 16) / 116.0;
                        if (F > 0.207)
                        {
                            X = Xn * F;
                            Y = Yn * F;
                            Z = Zn * F;
                            R = (-35.1051 + 3.240 * X - 1.537 * Y - 0.499 * Z) * 1.1622;
                            G = (-35.2127 - 0.969 * X + 1.876 * Y + 0.042 * Z) * 1.15867;
                            B = (-35.1448 + 0.056 * X - 0.204 * Y + 1.057 * Z) * 1.16;
                        }
                        else
                        {
                            X = Xn * 0.128 * (F - 16.0 / 116.0);
                            Y = Yn * 0.128 * (F - 16.0 / 116.0);
                            Z = Zn * 0.128 * (F - 16.0 / 116.0);
                            R = (3.240 * X - 1.537 * Y - 0.499 * Z) * 9.0798;
                            G = (-0.969 * X + 1.876 * Y + 0.042 * Z) * 9.0521;
                            B = (0.056 * X - 0.204 * Y + 1.057 * Z) * 9.0697;
                        }
                        res2.SetPixel(i, j, Color.FromArgb((int)R, (int)G, (int)B));

                        // a
                        X = Xn * 0.128 * ((double)a / 500.0);
                        R = (25.719 + 3.240 * X) * 4.9768;
                        G = (7.6318 - 0.969 * X) * 16.64;
                        B = (0.4445 + 0.056 * X) * 287.97;
                        res3.SetPixel(i, j, Color.FromArgb((int)R, (int)G, (int)B));

                        // b
                        X = 0;
                        Y = 0;
                        Z = Zn * 0.128 * ((double)b / 200.0);
                        R = (11.252 - 0.499 * Z) * 11.286;
                        G = (0.95466 + 0.042 * Z) * 134.086;
                        B = (24.0256 + 1.057 * Z) * 5.32797;
                        res4.SetPixel(i, j, Color.FromArgb((int)R, (int)G, (int)B));
                    }
                pictureBox2.Image = res2;
                pictureBox2.Refresh();
                pictureBox3.Image = res3;
                pictureBox3.Refresh();
                pictureBox4.Image = res4;
                pictureBox4.Refresh();
            }
            else return;
        }
        //
        // Перевод в модель YUV
        //
        private void yUVToolStripMenuItem_Click(object sender, EventArgs e)
        {
            double Y, U, V, R, G, B;
            if (pictureBox1.Image != null)
            {
                label14.Text = "Y:";
                label15.Text = "U:";
                label16.Text = "V:";

                Bitmap res2 = new Bitmap(img);
                Bitmap res3 = new Bitmap(img);
                Bitmap res4 = new Bitmap(img);
                for (int i = 0; i < res2.Width; ++i)
                    for (int j = 0; j < res2.Height; ++j)
                    {
                        Color c = res2.GetPixel(i, j);
                        Y = 0.299 * c.R + 0.587 * c.G + 0.114 * c.B;
                        U = -0.147 * c.R - 0.289 * c.G + 0.436 * c.B;
                        V = 0.615 * c.R - 0.515 * c.G - 0.100 * c.B;

                        // для Y
                        R = Y;
                        G = Y;
                        B = Y;
                        res2.SetPixel(i, j, Color.FromArgb((int)R, (int)G, (int)B));

                        // для U
                        R = 0;
                        G = (43.9161 - 0.395 * U) * 2.903;
                        B = (225.91776 + 2.032 * U) * 0.564;
                        res3.SetPixel(i, j, Color.FromArgb((int)R, (int)G, (int)B));

                        // для V
                        R = (178.7805 + 1.140 * V) * 0.713;
                        G = (90.9585 + 0.58 * V) * 1.402;
                        B = 0;
                        res4.SetPixel(i, j, Color.FromArgb((int)R, (int)G, (int)B));
                    }
                pictureBox2.Image = res2;
                pictureBox2.Refresh();
                pictureBox3.Image = res3;
                pictureBox3.Refresh();
                pictureBox4.Image = res4;
                pictureBox4.Refresh();
            }
            else return;
        }
        //
        // Перевод в модель HSV
        //
        private void hSBToolStripMenuItem_Click(object sender, EventArgs e)
        {
            double H = 361, S, V, T, P, Q, R = 0, G = 0, B = 0; int max, min;
            if (pictureBox1.Image != null)
            {
                label14.Text = "H:";
                label15.Text = "S:";
                label16.Text = "B:";

                Bitmap res2 = new Bitmap(img);
                Bitmap res3 = new Bitmap(img);
                Bitmap res4 = new Bitmap(img);
                for (int i = 0; i < res2.Width; ++i)
                    for (int j = 0; j < res2.Height; ++j)
                    {
                        Color c = res2.GetPixel(i, j);

                        max = Math.Max(c.R, Math.Max(c.G, c.B));
                        min = Math.Min(c.R, Math.Min(c.G, c.B));
                        V = max;
                        if (max == 0)
                        {
                            S = 0;
                        }
                        else
                        {
                            S = (double)((max - min)) / (double)(max);
                        }
                        if (max == min)
                        {
                            H = 0; 
                        }
                        else
                        {
                            if (max == c.R)
                            {
                                H = (double)((c.G - c.B)) / (double)((max - min));
                            }
                            else
                            {
                                if (max == c.G)
                                {
                                    H = 2.0 + (double)((c.B - c.R)) / (double)((max - min));
                                }
                                else
                                {
                                    if (max == c.B)
                                    {
                                        H = 4.0 + (double)((c.R - c.G)) / (double)((max - min));
                                    }
                                }
                            }
                            H = 60.0 * H;
                            if (H < 0)
                            {
                                H = H + 360.0;
                            }
                        }

                        // для H
                        if (S == 0) R = G = B = 255;
                        else
                        {
                            double sector = Math.Floor(H / 60); double frac = H / 60.0 - sector;
                            T = 0; P = 255 * (1 - frac); Q = 255 * frac;
                            switch ((int)sector)
                            {
                                case 0: { R = 255; G = Q; B = T; break; }
                                case 1: { R = P; G = 255; B = T; break; }
                                case 2: { R = T; G = 255; B = Q; break; }
                                case 3: { R = T; G = P; B = 255; break; }
                                case 4: { R = Q; G = T; B = 255; break; }
                                case 5: { R = 255; G = T; B = P; break; }
                            }
                        }
                        res2.SetPixel(i, j, Color.FromArgb((int)(R), (int)(G), (int)(B)));

                        // для S
                        if (S == 0) R = G = B = max;
                        else
                        {
                            T = 255 * (1 - S); P = 255; Q = 255 * (1 - S);
                            R = 255/*V*/; G = Q; B = T;

                        }
                        res3.SetPixel(i, j, Color.FromArgb((int)R, (int)G, (int)B));

                        // для B
                        if (S == 0) R = G = B = max;
                        else
                        {
                            T = 0; P = V; Q = 0;
                            R = V; G = Q; B = T;
                        }
                        res4.SetPixel(i, j, Color.FromArgb((int)R, (int)G, (int)B));
                    }
                pictureBox2.Image = res2;
                pictureBox2.Refresh();
                pictureBox3.Image = res3;
                pictureBox3.Refresh();
                pictureBox4.Image = res4;
                pictureBox4.Refresh();
            }
            else return;
        }
        //
        // Информация о пикселе
        //
        private void pictureBox1_MouseClick(object sender, MouseEventArgs e)
        {
            label2.Visible = true;
            label10.Visible = true;
            label11.Visible = true;
            label12.Visible = true;
            double L, a, b, X, Y, Z, U, V, H = 361, S, B, Xn = 255 * (0.412 + 0.358 + 0.18), Yn = 255 * (0.213 + 0.715 + 0.072), Zn = 255 * (0.019 + 0.119 + 0.95); ;
            Color c = (pictureBox1.Image as Bitmap).GetPixel(e.X, e.Y);
            label3.Text = c.R.ToString();
            label4.Text = c.G.ToString();
            label5.Text = c.B.ToString();
            if (label14.Text == "L:" && label15.Text == "a:" && label16.Text == "b:")
            {
                X = (0.412 * c.R + 0.358 * c.G + 0.180 * c.B) / Xn;
                Y = (0.213 * c.R + 0.715 * c.G + 0.072 * c.B) / Yn;
                Z = (0.019 * c.R + 0.119 * c.G + 0.950 * c.B) / Zn;
                L = 116 * f(Y) - 16.0;
                a = 500 * (f(X) - f(Y));
                b = 200 * (f(Y) - f(Z));
                label6.Visible = true;
                label17.Text = "L:";
                label7.Text = L.ToString();
                label18.Text = "a:";
                label8.Text = a.ToString();
                label19.Text = "b:";
                label9.Text = b.ToString();
            }
            if (label14.Text == "Y:" && label15.Text == "U:" && label16.Text == "V:")
            {
                Y = (0.299 * c.R + 0.587 * c.G + 0.114 * c.B);
                U = (-0.147 * c.R - 0.289 * c.G + 0.436 * c.B);
                V = (0.615 * c.R - 0.515 * c.G - 0.100 * c.B);
                label6.Visible = true;
                label17.Text = "Y:";
                label7.Text = Y.ToString();
                label18.Text = "U:";
                label8.Text = U.ToString();
                label19.Text = "V:";
                label9.Text = V.ToString();
            }
            if (label14.Text == "H:" && label15.Text == "S:" && label16.Text == "B:")
            {
                int min, max;
                max = Math.Max(c.R, Math.Max(c.G, c.B));
                min = Math.Min(c.R, Math.Min(c.G, c.B));
                B = max;
                if (max == 0)
                {
                    S = 0;
                }
                else
                {
                    S = (double)(max - min) / (double)(max);
                }
                if (max == min)
                {
                    H = 0; //H = UNDEFINED;
                }
                else
                {
                    if (max == c.R)
                    {
                        H = (double)(c.G - c.B) / (double)(max - min);
                    }
                    else
                    {
                        if (max == c.G)
                        {
                            H = 2.0 + (double)(c.B - c.R) / (double)(max - min);
                        }
                        else
                        {
                            if (max == c.B)
                            {
                                H = 4.0 + (double)(c.R - c.G) / (double)(max - min);
                            }
                        }
                    }
                    H = 60 * H;
                    if (H < 0)
                    {
                        H = H + 360;
                    }
                }
                label6.Visible = true;
                label17.Text = "H:";
                label7.Text = H.ToString();
                label18.Text = "S:";
                label8.Text = S.ToString();
                label19.Text = "B:";
                label9.Text = B.ToString();
            }
        }

        /*  private void textBox1_TextChanged(object sender, EventArgs e)
          {

          }  */
    }
}
