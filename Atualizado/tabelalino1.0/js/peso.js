function peso() {
    var form = document.getElementById('formulario');
    var dados =  new FormData(form);

    fetch("php/peso.php", {
        method: 'POST',
        body: dados

    });
}