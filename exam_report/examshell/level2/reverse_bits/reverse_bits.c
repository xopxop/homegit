unsigned char reverse_bits(unsigned char num)
{
	unsigned int ct;
	unsigned char reverse_num;

	ct = sizeof(num) * 8 - 1;
	reverse_num = num;
	num >>= 1;
	while (num)
	{
		reverse_num <<= 1;
		reverse_num |= num & 1;
		num >>= 1;
		ct--;
	}
	reverse_num <<= ct;
	return (reverse_num);
}
