-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Anamakine: 127.0.0.1
-- Üretim Zamanı: 09 Nis 2024, 15:08:24
-- Sunucu sürümü: 10.4.27-MariaDB
-- PHP Sürümü: 8.2.0

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Veritabanı: `espwebveritabani`
--

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `veriler`
--

CREATE TABLE `veriler` (
  `id` int(11) NOT NULL,
  `integerdb` int(10) NOT NULL,
  `stringdb` varchar(40) NOT NULL,
  `timedb` datetime NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Tablo döküm verisi `veriler`
--

INSERT INTO `veriler` (`id`, `integerdb`, `stringdb`, `timedb`) VALUES
(1, 25, 'merhaba', '2024-04-01 00:55:29'),
(2, 5, 'veritabani', '2024-04-01 01:38:19'),
(181, 35, 'Merhaba', '2024-04-03 23:35:14'),
(182, 35, 'Merhaba', '2024-04-03 23:35:19'),
(183, 35, 'Merhaba', '2024-04-03 23:35:24'),
(184, 35, 'Merhaba', '2024-04-03 23:35:30'),
(185, 35, 'Merhaba2', '2024-04-03 23:35:43'),

--
-- Dökümü yapılmış tablolar için indeksler
--

--
-- Tablo için indeksler `veriler`
--
ALTER TABLE `veriler`
  ADD PRIMARY KEY (`id`);

--
-- Dökümü yapılmış tablolar için AUTO_INCREMENT değeri
--

--
-- Tablo için AUTO_INCREMENT değeri `veriler`
--
ALTER TABLE `veriler`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=396;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
