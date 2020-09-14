import React, { useState, useEffect } from 'react'
import Filter from './components/Filter'
import Persons from './components/Persons'
import PersonForm from './components/PersonForm'
import personService from './services/persons'

const App = () => {
	const [ persons, setPersons ] = useState([])
	const [ newName, setNewName ] = useState('')
	const [ newNumber, setNewNumber ] = useState('')
	const [ newSearch, setNewSearch ] = useState('')

	const handleNameChange = (event) => {
		console.log(event.target.value)
		setNewName(event.target.value)
	}

	const handleNumberChange = (event) => {
		console.log(event.target.value)
		setNewNumber(event.target.value)
	}

	const handleSearchChange = (event) => {
		console.log(event.target.value)
		setNewSearch(event.target.value)
	}

	const toggleDeleteOf = (id) => {
		const result = window.confirm(`Delete ${persons.find(person => person.id === id).name}`)
		if (result) {
			personService
				.remove(id)
				.then(
					setPersons(persons.filter(n => n.id !== id))
				)
		}
	}

	const personsToShow = persons.filter(person => person.name.toLowerCase().includes(newSearch.trim().toLowerCase()))

	const hook = () => {
		personService
			.getAll()
			.then(initialPersons => {
				setPersons(initialPersons)
			})
	}
	useEffect(hook, [])

	const addPerson = (event) => {
		event.preventDefault()
		if (persons.find(person => person.name === newName)) {
			window.alert(newName + " is already added to phonebook")
		}
		else {
			const personObject = {
				name: newName,
				number: newNumber
			}

			personService
				.create(personObject)
				.then(returnedPerson => {
					setPersons(persons.concat(returnedPerson))
					setNewName('')
					setNewNumber('')
				})
		}
	}	

	return (
		<div>
			<h2>Phonebook</h2>
			<Filter type={newSearch} onChange={handleSearchChange} />
			<h3>add a new</h3>
			<PersonForm addPerson={addPerson} newName={newName} handleNameChange={handleNameChange} newNumber={newNumber} handleNumberChange={handleNumberChange} />
			<h3>Numbers</h3>
			<Persons personsToShow={personsToShow} toggleDeleteOf={toggleDeleteOf} />
		</div>
	)
}

export default App
