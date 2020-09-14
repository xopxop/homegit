import React from 'react'

const Person = ( {person , toggleDeleteOf} ) => {
	const lable = 'delete'

	return (
		<div>{person.name} {person.number} {}
		<button onClick={toggleDeleteOf}>{lable}</button>
		</div>
	)
}

export default Person
