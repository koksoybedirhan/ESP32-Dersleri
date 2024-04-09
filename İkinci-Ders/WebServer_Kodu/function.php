<?php 
    function getData()
    {
        include "db.php";

        $query = "SELECT * from veriler ORDER BY id DESC LIMIT 1";
        $result = mysqli_query($baglanti, $query);
        mysqli_close($baglanti);
        return $result;
    }
?> 