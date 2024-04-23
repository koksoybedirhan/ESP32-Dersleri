<?php
    include "db.php";
    include "function.php"; 

    echo "merhaba";

    if(!empty($_GET['IntDb']) && !empty($_GET['StringDb']))
    {
        $IntegerGet = $_GET['IntDb'];
        $StringGet = $_GET['StringDb'];

        echo "<br>";
        echo $IntegerGet;
        echo "<br>";
        echo $StringGet;

        $query = "INSERT INTO veriler (integerdb, stringdb)
        VALUES ('$IntegerGet','".$StringGet."')";
        $result = mysqli_query($baglanti, $query);
    }
?>

<?php
    $result = getData();
    while($data = mysqli_fetch_assoc($result)):
    echo "<br>";
    echo $data["integerdb"];
    echo "<br>";
    echo $data["stringdb"];
    endwhile;
?> 