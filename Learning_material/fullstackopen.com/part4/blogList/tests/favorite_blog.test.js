const listHelper = require('../utils/list_helper')

describe('favoriteBlog', () => {
	const blogs = [
		{
			_id: '5a422aa71b54a676234d17f8',
			title: 'Go To Statement Considered Harmful',
			author: 'Edsger W. Dijkstra',
			url: 'http://www.u.arizona.edu/~rubinson/copyright_violations/Go_To_Considered_Harmful.html',
			likes: 5,
			__v: 0
		},
		{
			title: "Canonical string reduction",
			author: "Edsger W. Dijkstra",
			likes: 12
		},
		{
			author: "Robert C. Martin",
			blogs: 3,
			likes: 12
		}
	]

	test('of favoriteBlog is found right', () => {
		const result = listHelper.favoriteBlog(blogs)
		expect(result).toBe(12)
	})

	test('of an empty list', () => {
		expect(listHelper.favoriteBlog([])).toBe(0)
	})
})