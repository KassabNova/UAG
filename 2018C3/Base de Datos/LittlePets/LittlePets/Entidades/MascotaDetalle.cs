using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace LittlePets.Entidades
{
    public class MascotaDetalle
    {
        public int IdMascota { get; set; }
        public string Dueño { get; set; }
        public string Cuidador { get; set; }
        public string Nombre { get; set; }
        public string Especie { get; set; }
        public string Raza { get; set; }
        public string Color { get; set; }
        public decimal Peso { get; set; }
        public string Sexo { get; set; }
        public DateTime Nacimiento { get; set; }


    }
}