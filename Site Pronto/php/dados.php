<?php
$servername = "localhost:3306";
$username = "root";
$password = "He@@2037";
$database = "alimentador";

// Cria a conexão com o banco de dados
$conn = new mysqli($servername, $username, $password, $database);

// Verifica a conexão
if ($conn->connect_error) {
    die("Conexão ao banco de dados falhou: " . $conn->connect_error);
}

// Consulta para recuperar os dados
$sql = "SELECT * FROM peso"; // Substitua "sua_tabela" pelo nome da tabela que você deseja usar
$result = $conn->query($sql);
?>

<!DOCTYPE html>
<html>
<head>
    <title>Tabela de Dados</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-image: image-set("../paginas/fundo.jpeg");
            background-size: cover;
            background-repeat: no-repeat;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
        }

        #container {
            background-color: #16ade9;
            border-radius: 10px;
            box-shadow: 0 0 20px rgba(0, 183, 255, 0.8);
            padding: 20px;
            text-align: center;
            font-weight: lighter;
        }

        table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 20px;
        }

        table th, table td {
            padding: 10px;
            border: 1px solid #fff;
        }

        table th {
            background-color: #08a8f0;
            color: #fff;
        }

        table tr:nth-child(even) {
            background-color: #f2f2f2;
        }

        table tr:nth-child(odd) {
            background-color: #e0e0e0;
        }
    </style>
</head>
<body>
    <div id="container">
        <h1>Tabela de Dados</h1>
        <table>
            <thead>
                <tr>
                    <th>Peso Balança</th>
                    <th>Peso</th>
                    <th>Data</th>
                </tr>
            </thead>
            <tbody>
                <?php
                if ($result->num_rows > 0) {
                    while ($row = $result->fetch_assoc()) {
                        echo "<tr>";
                        echo "<td>" . $row["pesobal"] . "</td>";
                        echo "<td>" . $row["peso"] . "</td>";
                        echo "<td>" . $row["data"] . "</td>";
                        echo "</tr>";
                    }
                } else {
                    echo "<tr><td colspan='3'>Nenhum dado encontrado</td></tr>";
                }
                $conn->close();
                ?>
            </tbody>
        </table>
    </div>
</body>
</html>
