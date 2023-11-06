<?php
    $nome = $_POST["nome"];
    $email = $_POST['email'];
    $senha = $_POST['senha'];

    $con= mysqli_connect('localhost', '', '', '');

    $query = "INSERT INTO entrada (nome, email, senha) VALUES ('$nome', '$email', '$senha')";

    mysqli_query($con,$query);
    ?>
