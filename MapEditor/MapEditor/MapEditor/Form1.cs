using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        static int TotalTile = 0;
        static List<Tile> ArrTile = new List<Tile>();
        static List<Tile> ArrTileSet = new List<Tile>();
        int CountArrTile = 0;
        int CountArrTileSet = 0;
        int ID = 0;

        private void Btn_CreateMap_Click(object sender, EventArgs e)
        {
            Bitmap BMap = new Bitmap(pictureBox1.Image);
            int Width = BMap.Width;
            int Height = BMap.Height;
            //// Tao danh sach Tile
            for (int i = 0; i < Height; i += int.Parse(Txt_Height.Text))
                for (int j = 0; j < Width; j += int.Parse(Txt_Width.Text))
                {
                    Tile tmp = new Tile();
                    RectangleF RteF = new RectangleF(j, i, int.Parse(Txt_Width.Text), int.Parse(Txt_Height.Text));

                    tmp.SetTile(BMap.Clone(RteF, BMap.PixelFormat), -1);
                    ArrTile.Add(tmp);
                }
            CountArrTile = ArrTile.Count();
            TotalTile = (Width * Height) / (int.Parse(Txt_Height.Text) * int.Parse(Txt_Width.Text));
            // Tao Tileset
            for (int i = 0; i < CountArrTile; i++)
            {
                if (i == CountArrTile - 1)
                {
                    if (ArrTile[i].id == -1)
                    {
                        ArrTile[i].id = ID;
                        ArrTileSet.Add(ArrTile[i]);
                    }
                }
                else if (ArrTile[i].id == -1)
                {
                    ArrTile[i].id = ID;
                    ArrTileSet.Add(ArrTile[i]);
                    for (int j = i + 1; j < CountArrTile; j++)
                    {

                        if (ArrTile[j].id == -1)
                        {
                            if (Tile.CompareImage(ArrTile[i].Bitmap, ArrTile[j].Bitmap))
                                ArrTile[j].id = ArrTile[i].id;
                        }

                    }
                    ID += 1;
                }
            }
            //Xuất TileSet
            CountArrTileSet = ArrTileSet.Count();
            for (int i = 0; i < CountArrTileSet; i++)
            {
                PictureBox Ptx = new PictureBox();
                Ptx.Image = ArrTileSet[i].Bitmap;
                Ptx.SizeMode = PictureBoxSizeMode.AutoSize;
                Flp_Title.Controls.Add(Ptx);
            }
        }
        //Text box khong duoc nhap chu
        private void Txt_Width_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!Char.IsDigit(e.KeyChar) && !Char.IsControl(e.KeyChar))
            {
                e.Handled = true;
            }
        }
        //Text box khong duoc nhap chu
        private void Txt_Height_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!Char.IsDigit(e.KeyChar) && !Char.IsControl(e.KeyChar))
            {
                e.Handled = true;
            }
        }
        public void WriteTxt()
        {
            using (StreamWriter sw = new StreamWriter("MaxtrixBMap.txt"))
            {
                Bitmap BMap = new Bitmap(pictureBox1.Image);
                int Width = BMap.Width;
                int Height = BMap.Height;
                int NbTileWidth = Width / int.Parse(Txt_Width.Text);//So tile tren 1 dong
                int NbTileHeight = Height / int.Parse(Txt_Height.Text);//So tile tren 1 cot
                int index = 0;
                sw.Write(CountArrTileSet + " " + NbTileWidth + " " + NbTileHeight);
                sw.WriteLine();
                for (int i = 0; i < CountArrTile; i++)
                {
                    sw.Write(ArrTile[i].id + " ");
                    index++;
                    if (index % NbTileWidth == 0)
                        sw.WriteLine();
                }

            }
        }
        public void TilesetOutput()
        {
            //Quy dinh so tile tren 1 dong Tilset de TileSet khong bi bop anh khi render 
            int ColTileSet = 80;
            int RowTileSet = CountArrTileSet / 80;
            if (RowTileSet == 0)//Phep chia / = 0 khi no co dong
                RowTileSet = 1;
            if (RowTileSet != 0 && RowTileSet % 80 != 0)//Neu phep chia / !=0 ma phep chia du cung !=0 thi co them 1 dong
                RowTileSet +=1;
            //Khoi tao bitmap voi chieu rong la chieu rong tile * so tile trong tile set, chieu cao la chieu cao tile 
            Bitmap TilesetOutput = new Bitmap(int.Parse(Txt_Width.Text) * ColTileSet, int.Parse(Txt_Height.Text)*RowTileSet, System.Drawing.Imaging.PixelFormat.Format32bppArgb);
            //Ghep anh
            using (Graphics g = Graphics.FromImage(TilesetOutput))
            {
                int IndexRow = 0;
                int IndexCol = 0;
                for (int i = 0; i < CountArrTileSet; i++)
                {
                    IndexRow = i / 80;
                    if (IndexRow==0)
                    {
                        g.DrawImage(ArrTileSet[i].Bitmap, i * int.Parse(Txt_Width.Text), 0);
                    }
                    else
                    {
                        IndexCol = i - 80 * IndexRow;
                        g.DrawImage(ArrTileSet[i].Bitmap, IndexCol* int.Parse(Txt_Width.Text),IndexRow* int.Parse(Txt_Height.Text));
                    }
                }
                g.Save();
            }
            //using (Graphics g = Graphic)
                TilesetOutput.Save("Tileset.png", ImageFormat.Png);
            TilesetOutput.Dispose();
        }
        private void Btn_Output_Click(object sender, EventArgs e)
        {
            WriteTxt();
            TilesetOutput();
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            ArrTile.RemoveRange(0, ArrTile.Count);
            ArrTileSet.RemoveRange(0, ArrTileSet.Count);
        }

        private void Btn_Open_Click(object sender, EventArgs e)
        {
            OpenFileDialog open = new OpenFileDialog();
            if (open.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                Bitmap tmpBm = new Bitmap(open.FileName);
                pictureBox1.Image = tmpBm;
            }
        }
    }
}
