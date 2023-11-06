<?php
if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $email = $_POST['email'];
    $senha = $_POST['senha'];

    // Conecte-se ao seu banco de dados. Substitua as informações do banco de dados apropriadas.
    $con= mysqli_connect('localhost:3306', 'root', 'He@@2037', 'alimentador');

    // Verifique a conexão com o banco de dados
    if (!$con) {
        die("Erro na conexão com o banco de dados: " . mysqli_connect_error());
    }

    // Consulta SQL para verificar o email e senha
    $query = "SELECT * FROM entrada WHERE email = '$email' AND senha = '$senha'";
    $result = mysqli_query($con, $query);

    if (mysqli_num_rows($result) > 0) {
        echo json_encode(array("autenticado" => true));
    } else {
        echo json_encode(array("autenticado" => false));
    }

    // Feche a conexão com o banco de dados
    mysqli_close($con);
} else {
    // Caso a requisição não seja POST, retorne um erro
    echo json_encode(array("erro" => "Método não suportado"));
}
?>