using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace MapEditor
{
    class Tile
    {
        private Bitmap bitmap;
        private int Id;
        public void SetTile(Bitmap bmp, int ID)
        {
            bitmap = bmp;
            Id = ID;
        }
        public Bitmap Bitmap { get => bitmap; set => bitmap = value; }
        public int id { get => Id; set => Id = value; }
        //So sanh 2 bit map
        public static bool CompareImage(Bitmap bmp1, Bitmap bmp2)
        {
            string tmp1, tmp2;
            if ((bmp1.Width == bmp2.Width) && (bmp1.Height == bmp2.Height))
            {
                for (int i = 0; i < bmp1.Width; i++)
                    for (int j = 0; j < bmp1.Height; j++)
                    {
                        tmp1 = bmp1.GetPixel(i, j).ToString();
                        tmp2 = bmp2.GetPixel(i, j).ToString();
                        if (tmp1 != tmp2)
                            return false;
                    }
                return true;
            }
            return false;
        }
    }
}
