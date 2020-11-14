import React from 'react'

const Footer = () => {
	const footerStyle = {
		color: 'green',
		fontStyle: 'italic',
		fontSize: 16
	}
	return (
		<div>
			<br style={footerStyle}/>
			<em>Note app, Department of Computer Science, University of Helsinki 2020</em>
		</div>
	)
}

export default Footer