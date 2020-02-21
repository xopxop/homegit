unsigned char swap_bits(unsigned char num)
{
	unsigned char swapped_bits_num;
	unsigned char temp_num;
	int ct;

	ct = sizeof(unsigned char) * 4;
	temp_num = num;
	num >>= ct;
	temp_num <<= ct;
	swapped_bits_num = num ^ temp_num;
	return swapped_bits_num;
}
