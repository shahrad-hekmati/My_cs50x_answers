SELECT
  title,
  YEAR
FROM
  movies
WHERE
  title LIKE "Harry potter%"
ORDER BY
  YEAR
