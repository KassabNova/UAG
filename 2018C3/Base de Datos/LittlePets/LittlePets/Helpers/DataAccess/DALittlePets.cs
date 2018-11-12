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
        private static string CONEXION = "Data Source = localhost; Initial Catalog = LittlePets; Integrated Security = SSPI";
        public static List<Mascota> ObtenerMascota()
        {
            List<Mascota> mascotas = new List<Mascota>();

            SqlConnection conexion = new SqlConnection("Data Source = localhost; Initial Catalog = LittlePets; Integrated Security = SSPI");

            string query = "select * from tblMascota";
            try
            {
                using (conexion)
                {
                    using (SqlCommand comando = new SqlCommand(query, conexion))
                    {

                        comando.CommandTimeout = 600;
                        comando.CommandType = CommandType.Text;
                        //comando.Parameters.AddWithValue("@IdMensaje", idMensaje);
                        conexion.Open();
                        using (SqlDataReader lector = comando.ExecuteReader())
                        {
                            if (lector.HasRows)
                            {
                                while (lector.Read())
                                {

                                    mascotas.Add(new Mascota()
                                    {
                                        IdMascota = Int32.Parse(lector["IdMascota"].ToString()),
                                        Nombre = lector["Nombre"].ToString(),
                                        Especie = lector["Especie"].ToString(),
                                        Raza = lector["Raza"].ToString()
                                    });

                                }
                            }
                            conexion.Close();
                        }
                    }
                }

            }
            catch
            {
                mascotas = null;
            }
            finally
            {
                if (conexion != null && conexion.State != ConnectionState.Closed)
                {
                    conexion.Close();
                }
            }

            return mascotas;
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


        public static List<Mascota> ObtenerAnalisis()
        {
            List<Mascota> mascotas = new List<Mascota>();

            SqlConnection conexion = new SqlConnection(CONEXION);

            string query = "select * from tblMascota";
            try
            {
                using (conexion)
                {
                    using (SqlCommand comando = new SqlCommand(query, conexion))
                    {

                        comando.CommandTimeout = 600;
                        comando.CommandType = CommandType.Text;
                        //comando.Parameters.AddWithValue("@IdMensaje", idMensaje);
                        conexion.Open();
                        using (SqlDataReader lector = comando.ExecuteReader())
                        {
                            if (lector.HasRows)
                            {
                                while (lector.Read())
                                {

                                    mascotas.Add(new Mascota()
                                    {
                                        IdMascota = Int32.Parse(lector["IdMascota"].ToString()),
                                        Dueño = lector["NombreDueño"].ToString(),
                                        Nombre = lector["NombreMascota"].ToString(),
                                        Especie = lector["Especie"].ToString(),
                                        Raza = lector["Raza"].ToString()
                                    });

                                }
                            }
                            conexion.Close();
                        }
                    }
                }

            }
            catch
            {
                mascotas = null;
            }
            finally
            {
                if (conexion != null && conexion.State != ConnectionState.Closed)
                {
                    conexion.Close();
                }
            }

            return mascotas;
        }

        public static List<Producto> ObtenerProductos()
        {
            List<Producto> productos = new List<Producto>();
            SqlConnection conexion = new SqlConnection(CONEXION);

            string query = "select * from tblProducto order by Nombre";
            try
            {
                using (conexion)
                {
                    using (SqlCommand comando = new SqlCommand(query, conexion))
                    {

                        //comando.CommandTimeout = 600;
                        comando.CommandType = CommandType.Text;
                        //comando.Parameters.AddWithValue("@IdMensaje", idMensaje);
                        conexion.Open();
                        using (SqlDataReader lector = comando.ExecuteReader())
                        {
                            if (lector.HasRows)
                            {
                                while (lector.Read())
                                {

                                    productos.Add(new Producto()
                                    {

                                        IdProducto = Int32.Parse(lector["IdProducto"].ToString()),
                                        Nombre = lector["Nombre"].ToString(),
                                        Cantidad = Int32.Parse(lector["Cantidad"].ToString()),
                                        Precio = Double.Parse(lector["Precio"].ToString())
                                    });

                                }
                            }
                            conexion.Close();
                        }
                    }
                }

            }
            catch
            {
                productos = null;
            }
            finally
            {
                if (conexion != null && conexion.State != ConnectionState.Closed)
                {
                    conexion.Close();
                }
            }

            return productos;
        }

        public static void ActualizarInventario(int idProducto, int cantidad)
        {


            SqlConnection conexion = new SqlConnection(CONEXION);

            string query = "update tblProducto SET Cantidad = @Cantidad  where  IdProducto = @idProducto";
            try
            {
                using (conexion)
                {
                    using (SqlCommand comando = new SqlCommand(query, conexion))
                    {

                        comando.CommandTimeout = 600;
                        comando.CommandType = CommandType.Text;
                        comando.Parameters.AddWithValue("@IdProducto", idProducto);
                        comando.Parameters.AddWithValue("@Cantidad", cantidad);

                        conexion.Open();
                        using (SqlDataReader lector = comando.ExecuteReader())
                        {
                            
                            conexion.Close();
                        }
                    }
                }



            }
            catch (Exception e)
            {
                throw new Exception(string.Format("Error interno. Por favor, inténtelo más tarde."));
            }
            finally
            {
                if (conexion != null && conexion.State != ConnectionState.Closed)
                {
                    conexion.Close();
                }
            }
        }
    }
}