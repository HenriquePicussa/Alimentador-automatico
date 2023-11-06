<?php
    $nome = $_POST["nome"];
    $email = $_POST['email'];
    $senha = $_POST['senha'];

    $con= mysqli_connect('localhost:3306', 'root', 'He@@2037', 'alimentador');

    $query = "INSERT INTO entrada (nome, email, senha) VALUES ('$nome', '$email', '$senha')";

    mysqli_query($con,$query);
    ?>