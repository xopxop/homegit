SELECT UPPER(last_name) AS 'NAME'
FROM
	user_card
INNER JOIN
	member ON user_card.id_user=member.id_member
INNER JOIN
	subscription ON member.id_member=subscription.id_sub
WHERE
	subscription.price > 42
ORDER BY
	last_name, last_name ASC;