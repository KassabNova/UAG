var modal;

$(document).ready(function () {
    // alert("Esto es una Prueba");


    $('.glyphicon-plus').on('click', function () {
        var input = $(this).prev().find("input");
        var cantidad = parseInt(input.val()) + 1;
        $(this).prev().find("input").val(cantidad);
    });
    $('.glyphicon-minus').on('click', function () {

        var input = $(this).next().find("input");
        if (parseInt(input.val()) > 1) {
            var cantidad = parseInt(input.val()) - 1;
            $(this).next().find("input").val(cantidad);
        }
    });
    $('#asdf').on('click', function () {

        alert("ASDF");
    });

    $('.inventario').on('click', function () {
        var IdProducto = $(this).attr("data-id");
        var Inventario = $(this).attr("data-inventario");
        var Cantidad = $('#contador-' + IdProducto).val();
        var Accion = "inventario";
        $.ajax({
            cache: false,
            type: "POST",
            url: '/Home/ActualizarInventario',
            data: {
                idProducto: IdProducto,
                inventario: Inventario,
                cantidad: Cantidad,
                accion: Accion
            },
            success: function (response) {
                $.ajax({
                    cache: false,
                    type: "POST",
                    url: '/Home/ActualizarProductos',
                    data: {},
                    success: function (response) {
                        $('#wrapper').remove();
                        $("#productos").html(response.data);
                    }

                });

            },
            error: function (response) {
                alert("Fracasado");
            }
        });
    });

    $('.carrito').on('click', function () {
        var IdProducto = $(this).attr("data-id");
        var Inventario = $(this).attr("data-inventario");
        var Cantidad = $('#contador-' + IdProducto).val();
        var Accion = "carrito";
        if ((parseInt(Inventario) - parseInt(Cantidad) > 0)) {

            $.ajax({
                cache: false,
                type: "POST",
                url: '/Home/ActualizarInventario',
                data: {
                    idProducto: IdProducto,
                    inventario: Inventario,
                    cantidad: Cantidad,
                    accion: Accion
                },
                success: function (response) {
                    $.ajax({
                        cache: false,
                        type: "POST",
                        url: '/Home/ActualizarProductos',
                        data: {},
                        success: function (response) {
                            $("#productos").html(response.data);
                        }

                    });

                },
                error: function (response) {
                    alert("Fracasado");
                }
            });

        }
        else {
            alert("No hay inventario suficiente");
        }

    });

});

