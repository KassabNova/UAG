var modal;

$(document).ready(function () {
    alert("Esto es una Prueba");

});

$('.detalle-Mascota').on('click', function () {
    alert($(this).data("id"));
    //$.ajax({
    //    url: '/Principal/ObtenerMascotaDetalle',
    //    data: { id: $(this).data("id") },
    //    type: 'GET',
    //    success: function (data) {
    //    }
    //});
});
