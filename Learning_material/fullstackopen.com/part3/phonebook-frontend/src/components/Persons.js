import React from 'react'
import Person from './Person'


const Persons = ( {personsToShow, toggleDeleteOf }) => {
	return (
		<div>
			{personsToShow.map((person, i) =>
				<Person
					key={i}
					person={person}
					toggleDeleteOf={() => toggleDeleteOf(person.id)}
				/>
			)}
		</div>
	)
}

export default Persons
