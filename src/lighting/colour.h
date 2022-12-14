#ifndef FCOLOUR_H
#define FCOLOUR_H
double HueToRgb(double p, double q, double t) {
	if (t < 0) t += 1;
	if (t > 1) t -= 1;
	if (t < 1 / 6.0) return p + (q - p) * 6 * t;
	if (t < 1 / 2.0) return q;
	if (t < 2 / 3.0) return p + (q - p) * (2 / 3.0 - t) * 6;
	return p;
}

void HslToRgb(double hue, double saturation, double lightness, uint8_t& red, uint8_t& green, uint8_t& blue) {
	double r, g, b;

	if (saturation == 0) {
		r = g = b = lightness; // achromatic
	} else {
		auto q = lightness < 0.5 ? lightness * (1 + saturation) : lightness + saturation - lightness * saturation;
		auto p = 2 * lightness - q;
		r = HueToRgb(p, q, hue + 1 / 3.0);
		g = HueToRgb(p, q, hue);
		b = HueToRgb(p, q, hue - 1 / 3.0);
	}

	red = static_cast<uint8_t>(r * 255);
	green = static_cast<uint8_t>(g * 255);
	blue = static_cast<uint8_t>(b * 255);
}
#endif
