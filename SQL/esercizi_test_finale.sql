--9

select customer_id
	from customer
		where active = 1
		and address_id between 100 and 200


--10

select address_id
	from address
		where city_id < 600
		and district in ('Taipei')
--11

select customer_id
	from customer
		where first_name like 'V%'
--12
select count (*) as total_customers
	from customer
		where first_name like 'V%'
--13
select count (rating) 
	,avg(rental_duration) 
		from film
			group by rating
				order by rating

--14
select film.film_id
	from film
		inner join inventory
			on inventory.film_id = film.film_id
		inner join film_category
			on film_category.film_id = film.film_id
				where inventory.store_id = 1
				and film_category.category_id between 4 and 10
					group by film.film_id
	
--15
select rental_rate
	,category_id
	,rating
		from film
			inner join film_category
				on film.film_id= film_category.film_id
					where category_id = 11
						group by film.rental_rate, film_category.category_id,rating
							order by rental_rate desc

--16
select film.film_id
	,round(avg(film.length)) as lunghezza_media
	,avg(rental_rate) as rental_medio
	,actor_id
	from film
		inner join film_actor
			on film.film_id = film_actor.film_id
			where film.length < 100
				group by film.film_id,film_actor.actor_id,film.length
					order by rental_medio desc
						limit 10

--17
select 
	from film
		inner join category
			on film.film_id = category.film_id
				
