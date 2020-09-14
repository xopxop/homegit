import React from 'react'

const Total = ( {parts} ) => {
	const total = parts.reduce((sum, parts) => sum + parts.exercises, 0)

	return (
			<p><strong>total of {total} exercises</strong></p>
	)
}

export default Total
