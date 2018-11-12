using LittlePets.Entidades;
using LittlePets.Helpers.DataAccess;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace LittlePets.Controllers
{
    public class PrincipalController : Controller
    {
        // GET: Principal
        public ActionResult Index()
        {
            ViewBag.Message = "Mascotas";
            List<Mascota> mascotas = new List<Mascota>();
            mascotas = DALittlePets.ObtenerMascota();
            if(mascotas == null)
            {
                mascotas = new List<Mascota>();
                Mascota vacio = new Mascota();
                vacio.IdMascota = 123;
                vacio.Dueño = "ABC";
                vacio.Nombre = "DEF";
                vacio.Especie = "ABGHIC";
                vacio.Raza = "ZXCV";
                mascotas.Add(vacio);
            }
            return View("Mascota", mascotas);
        }
        //public ActionResult ObtenerMascota()
        //{
        //    ViewBag.Message = "Mascotas";
        //    List<Mascota> mascota = new List<Mascota>();
        //    mascota = DALittlePets.ObtenerMascota();
        //    return View("Mascota", mascota);
        //}

        public ActionResult ObtenerMascotaDetalle(int idmascota)
        {
            MascotaDetalle mascota = new MascotaDetalle();
            mascota = DALittlePets.ObtenerMascotaDetalle(idmascota);
            return View("MascotaDetalle", mascota);
        }
    }
}