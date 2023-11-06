function gravar() {
    var form = document.getElementById('formulario');
    var dados =  new FormData(form);

    fetch("php/login.php", {
        method: 'POST',
        body: dados

    });
}

function realizarLogin() {
    var form = document.getElementById('formulario2');
    var dados = new FormData(form);

    fetch("../php/logar.php", {
        method: 'POST',
        body: dados
    })
    .then(response => response.json())
    .then(data => {
        if (data.autenticado) {
            alert("Login bem-sucedido. Redirecionando para a página de boas-vindas.");
            window.location.href = "Dados.html";
        } else {
            alert("Credenciais inválidas. Tente novamente.");
        }
    });
}