using LittlePets.Entidades;
using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;

namespace LittlePets.Helpers.DataAccess
{
    public class DALittlePets
    {
        public static List<Mascota> ObtenerMascota()
        {
            List<Mascota> mascota = null;

            SqlConnection conexion = new SqlConnection("Data Source=(LocalDB)\\Prueba;Initial Catalog=LittlePets; Integrated Security=true");
            SqlCommand comando = new SqlCommand("spObtenerMascota", conexion);
            conexion.Open();
            SqlDataReader dr = comando.ExecuteReader();
            if (dr.HasRows)
            {
                mascota = new List<Mascota>();
                while (dr.Read())
                {
                    Mascota m = new Mascota();
                    m.IdMascota = Convert.ToInt32(dr["IdMascota"]);
                    m.Dueño = Convert.ToString(dr["NombreDueño"]);
                    m.Nombre = Convert.ToString(dr["NombreMascota"]);
                    m.Especie = Convert.ToString(dr["Especie"]);
                    m.Raza = Convert.ToString(dr["Raza"]);

                    mascota.Add(m);
                }
                mascota.TrimExcess();
            }
            conexion.Close();
            return mascota;
        }

        public static MascotaDetalle ObtenerMascotaDetalle(int idmascota)
        {
            MascotaDetalle mascota = null;

            SqlConnection conexion = new SqlConnection("Data Source=(LocalDB)\\Prueba;Initial Catalog=LittlePets; Integrated Security=true");
            SqlCommand comando = new SqlCommand("spObtenerMascotaDetalle", conexion);
        

            SqlDataReader dr = comando.ExecuteReader();
            if (dr.HasRows)
            {
                mascota = new MascotaDetalle();
                if (dr.Read())
                {
                    mascota.IdMascota = Convert.ToInt32(dr["IdMascota"]);
                    mascota.Dueño = Convert.ToString(dr["NombreDueño"]);
                    mascota.Nombre = Convert.ToString(dr["NombreMascota"]);
                    mascota.Especie = Convert.ToString(dr["Especie"]);
                    mascota.Raza = Convert.ToString(dr["Raza"]);
                    mascota.Color = Convert.ToString(dr["Color"]);
                    mascota.Peso = Convert.ToDecimal(dr["Peso"]);
                    mascota.Sexo = Convert.ToString(dr["Sexo"]);
                    mascota.Nacimiento = Convert.ToDateTime(dr["Nacimiento"]);

                }
            }
            conexion.Close();
            return mascota;
        }
    }
}