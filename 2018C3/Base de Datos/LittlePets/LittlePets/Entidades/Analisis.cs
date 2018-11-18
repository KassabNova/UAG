using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace LittlePets.Entidades
{
    public class Analisis
    {
        public int IdAnalisis { get; set; }
        public string Nombre { get; set; }
        public string Tipo { get; set; }
        public string Descripcion { get; set; }
        public double Precio { get; set; }
        public int IdCentro { get; set; }
        public string Centro { get; set; }
        public string Domicilio { get; set; }
        public string Telefono { get; set; }


    }
}
