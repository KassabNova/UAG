using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace LittlePets.Entidades
{
    public class Producto
    {
        public int IdProducto { get; set; }
        public string Nombre { get; set; }
        public int Cantidad { get; set; }
        public double Precio { get; set; }
        public Proveedor proveedor;

    }
}
