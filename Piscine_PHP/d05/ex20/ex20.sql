SELECT genre.id_genre, genre.name ,distrib.id_distrib, distrib.name, film.title
FROM film
LEFT JOIN genre ON genre.id_genre = film.id_genre
LEFT JOIN distrib ON distrib.id_distrib = film.id_distrib
WHERE
	film.id_genre BETWEEN 4 AND 8;