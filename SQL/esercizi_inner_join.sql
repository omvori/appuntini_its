--es 1

select film_actor.actor_id
	,rental_rate
		from film
			inner join film_actor
				on film.film_id = film_actor.film_id
					where rental_rate > 3
						group by film_actor.actor_id, rental_rate
							order by rental_rate desc

--es 2

select customer_id
	, phone
		from customer
			inner join address
				on customer.address_id = address.address_id
					where phone like '%58%' and phone like '%83%'
--es 3 
select rental_id
	,amount
		from payment
			where amount > 5
				order by amount asc
--es 4
create view intermediate_join(
	select payment_id
		,staff_id
		,rental_id
		,case 
			when amount > 9 and staff_id = 1
				then 'Staff 1 Alto valore'
			when amount > 9 and staff_id = 2
				then 'Staff 2 Alto valore'
			else 'Non vali nulla'
			end as topo_gigio
		from payment
			where payment_date > '15-02-2007'
				/*where extract(month from payment_date)= '02' 
			and extract(day from payment_date) = '15'
			and extract(year from payment_date)= '2007' --soluzione alternativa
			*/
			
)

--es 5
select concat(left(city,2),right(country,2),city_id,country.country_id
	 ,	(country.last_update - city.last_update)) as l_unione
		from city
			inner join country
				on city.country_id = country.country_id
					order by country.country_id 
--es 6
select payment.rental_id
	, payment.staff_id
	, payment.amount
	, inventory_id
	from staff
		inner join payment 
			on staff.staff_id = payment.staff_id
		inner join rental
			on payment.rental_id = rental.rental_id
		--inner join rental
			--on staff.staff_id = rental.staff_id
		where payment.amount > 3 
		and staff.staff_id = 1
		and payment.staff_id = 1 
		and inventory_id in (20,21,22,6,8) 
		or inventory_id >=40
	