WITH
    cte AS (
        SELECT DISTINCT
            COALESCE(u.name, 'not defined') AS name, COALESCE(u.lastname, 'not defined') AS lastname, b.type AS type, b.money AS money, COALESCE(c.name, 'not defined') AS currency_name, COALESCE(
                FIRST_VALUE(c.rate_to_usd) OVER (
                    PARTITION BY
                        c.id
                    ORDER BY c.updated DESC
                ), 1
            ) AS last_rate_to_usd
        FROM
            balance b
            FULL JOIN "user" u ON b.user_id = u.id
            FULL JOIN currency c ON b.currency_id = c.id
    )
SELECT DISTINCT
    name,
    lastname,
    type,
    SUM(money) OVER (
        PARTITION BY
            name, lastname, type, currency_name, last_rate_to_usd
    ) AS volume,
    currency_name,
    last_rate_to_usd,
    (
        SUM(money) OVER (
            PARTITION BY
                name, lastname, type, currency_name, last_rate_to_usd
        ) * last_rate_to_usd
    ) AS total_volume_in_usd
FROM cte
ORDER BY name DESC, lastname ASC, type ASC;