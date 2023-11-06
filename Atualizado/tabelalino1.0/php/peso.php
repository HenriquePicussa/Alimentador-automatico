<?php
    $peso = $_POST["nome"];
    $pesobal = $_POST['email'];

    $con= mysqli_connect('localhost:3306', 'root', 'He@@2037', 'alimentador');

    $query = "INSERT INTO valores (Pesobal, Peso) VALUES ('$pesobal', '$peso')";

    mysqli_query($con,$query);

    ?>