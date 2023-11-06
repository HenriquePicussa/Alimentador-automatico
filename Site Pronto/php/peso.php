<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $pesobal = $_POST["pesobal"];
    $peso = $_POST["peso"];

    // Verifique se os valores não estão vazios
    if (!empty($pesobal) && !empty($peso)) {
        $con = mysqli_connect('localhost', 'root', 'He@@2037', 'alimentador');

        // Use prepared statements para evitar injeção de SQL
        $query = "INSERT INTO peso (pesobal, peso) VALUES (?, ?)";
        $stmt = mysqli_prepare($con, $query);

        // Associe os valores aos marcadores de posição na consulta
        mysqli_stmt_bind_param($stmt, "ss", $pesobal, $peso);

        // Execute a consulta preparada
        if (mysqli_stmt_execute($stmt)) {
            echo "Inserção bem-sucedida.";
        } else {
            echo "Erro na inserção: " . mysqli_error($con);
        }

        // Feche a consulta preparada e a conexão
        mysqli_stmt_close($stmt);
        mysqli_close($con);
    } else {
        echo "Os valores de 'pesobal' e 'peso' não podem estar vazios.";
    }
} else {
    echo "Apenas solicitações POST são permitidas.";
}
?>
