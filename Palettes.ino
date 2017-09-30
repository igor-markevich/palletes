#include <FastLED.h>

#define RS1  A11 	//Rotary Switch 1 connected to Analog Pin A0. 10 kOhm resistance between each connector of switch. So, it become to potentiometer with positions.
#define RS2  A12 	//+5V to 1st contact => 10 kOhm (2nd)=>10 kOhm (3rd)....=>10kOhm (6th) to ground, coommon to A0 pin
#define POT1  A1	 //potentiometer 1 connected to Analog Pin A2.
#define POT2  A2
#define POT3  A3
#define POT4  A4
#define POT5  A5
#define LED_PIN    6
#define NUM_LEDS 60// 174
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
#define PIXEL_POSITION map(analogRead(POT4),0,1020,0,NUM_LEDS)
#define SPEED_RATIO YP/32 //cases: 3
#define SPEED_DELAY 255-YP// cases 5,13,15
#define RETURN_DELAY 5*YP
#define MAX_HUE_SPEED 3
#define HUE_SPEED  map(analogRead(POT3),0,1023,0, MAX_HUE_SPEED)
#define THIS_DELAY MAX_HUE_SPEED-HUE_SPEED
#define BALL_COUNT 5
int sectors [ 6 ] =
            {
	            0,
	            41,
	            83,
	            120,
	            138,
	            174
	        };
CRGB leds [ NUM_LEDS ];
CRGB Leds [ NUM_LEDS ];
int Rotary1Value = 0;
int Rotary2Value = 0;
int RP;
int GP;
int BP;
int YP;
int WP;
byte RB;
byte GB;
byte BB;
int pos1;
int pos2;
int pos;
CRGBPalette16 currentPalette;
TBlendType currentBlending;
int LedMode [ 6 ] [ 6 ] =
#if (1)
		{
	                {1, 2, 3, 4, 5, 6 },
	                {7, 8, 9, 10, 11, 12 },
	                {13, 14, 15, 16, 17, 18 },
	                {19, 20, 21, 22, 23, 24 },
	                {25, 26, 27, 28, 29, 30 },
	                {31, 32, 33, 34, 35, 36 } };
#endif
void setup () {
	Serial.begin(9600);
	delay(1000); // power-up safety delay
	FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS)
	                                                               .setCorrection(TypicalLEDStrip);
	currentPalette = RainbowColors_p;
	currentBlending = LINEARBLEND;
	set_max_power_in_volts_and_milliamps(5, 2000);
}
#if (1) //pallist
CRGBPalette16 Pallist [ ] =
            {
            	lines_gp,									//1
	            colorcube_gp,						//2
	            RainbowColors_p,					//3
	            RainbowStripeColors_p,		//4
	            OceanColors_p,						//5
	            PartyColors_p,						//6
	            LavaColors_p,						//7
	            HeatColors_p,						//8
	            otis_gp,								//9
	            CloudColors_p,						//10
	            ForestColors_p,			//11
	            Primary_1_gp,				//12
	            curry_house_gp,		//13
	            UKRAINE_gp //14
	    };
#endif
void loop () {
	//setAll(0,0,0);
	checkPos();
	Debugging();
	switch (pos)
	{
		case 1:
			setAll(RP, GP, BP);
			break;
		case 2:
			for (int i = 0; i < NUM_LEDS; i++) {
				leds [ i ] = CHSV(YP, BP, 255);
			}
			showStrip();
			break;
		case 3: //monocolor dynamic
			static int hue;
			for (int i = 0; i < NUM_LEDS; i++) {
				leds [ i ] = CHSV(hue, BP, 255);
			}
			hue += HUE_SPEED;
			showStrip();
			break;
		case 4:
			pasha(RP, GP, BP, PIXEL_POSITION);
			break;
		case 5:
			//checkPos();
			//setAll(0,0,0);
			cylon();
			break;
		case 6:
			confetti();
			//RGBLoop();
			break;
		case 7:
			case 8:
			case 9:
			case 10:
			case 11:
			checkPos();
			for (int i = sectors [ pos1 ]; i < sectors [ pos1 + 1 ]; i++) {
				Leds [ i ] = CRGB(RP, GP, BP);
			}
			delay(500);
			break;

		case 12:
			checkPos();
			for (int i = 0; i < NUM_LEDS; i++) {
				leds [ i ] = Leds [ i ];
			}
			showStrip();
			break;

		case 13:
			Fire(55, 120, SPEED_DELAY);
			break;
		case 14:
			BouncingBalls(RB, GB, BB, map(analogRead(POT4),0,1023,1,BALL_COUNT));
			break;
		case 15:
			CylonBounce(RB, GB, BB, 4, SPEED_DELAY, 10);
			break;

		case 16:
			bpm();
			break;
		case 17:
colorWipe();
			break;

		case 18:
			break;
		default:
			igor(pos - 18);
	}
	showStrip();
	//FastLED.delay(25);
}
void checkPos () {
	Rotary1Value = analogRead(RS1);
	Rotary2Value = analogRead(RS2);
	pos1 = Rotary1Value / 177; // map() function doesn't work properly, don't know why. Need to map analogRead value to position number like this.
	pos2 = Rotary2Value / 177;
	pos = LedMode [ pos2 ] [ pos1 ];
	RP = map(analogRead(POT1), 6, 1013, 0, 255);
	GP = map(analogRead(POT2), 6, 1013, 0, 255);
	BP = map(analogRead(POT3), 6, 1013, 0, 255);
	YP = map(analogRead(POT4), 6, 1013, 0, 255);
	WP = map(analogRead(POT5), 6, 1013, 0, 155);
	RB = map(analogRead(POT1), 6, 1013, 0, 0xff);
	GB = map(analogRead(POT2), 6, 1013, 0, 0xff);
	BB = map(analogRead(POT3), 6, 1013, 0, 0xff);
}
void Debugging () {
	Serial.print("Red=");
	Serial.print(analogRead(POT1));
	Serial.print("; Green=");
	Serial.print(analogRead(POT2));
	Serial.print("; Blue=");
	Serial.print(analogRead(POT3));
	Serial.print("; Yellow=");
	Serial.print(analogRead(POT4));
	Serial.print("; White=");
	Serial.print(analogRead(POT5));
	Serial.print("; POS1=");
	Serial.print(pos1);
	Serial.print("; POS2=");
	Serial.print(pos2);
	Serial.print("; LedMode= ");
	Serial.println(pos);
	//delay(100);
}
void setAll (byte red, byte green, byte blue) {
	for (int i = 0; i < NUM_LEDS; i++) {
		setPixel(i, red, green, blue);
	}
	showStrip();
}

void FillLEDsFromPaletteColors (uint8_t colorIndex) {
	uint8_t brightness = 255;

	for (int i = 0; i < NUM_LEDS; i++) {
		leds [ i ] =
		        ColorFromPalette(currentPalette, colorIndex, brightness, currentBlending);
		colorIndex += 1;
	}
}
void showStrip () {
	checkPos();
	FastLED.setBrightness(WP);
	FastLED.show();
}
void setPixel (int Pixel, byte red, byte green, byte blue) {
	leds [ Pixel ].r = red;
	leds [ Pixel ].g = green;
	leds [ Pixel ].b = blue;
}
void pasha (int red, int green, int blue, int Sector) {
	//Sector = map(analogRead(POT4), 0, 1023, 0, NUM_LEDS);
	//for (int i = 0; i < NUM_LEDS; i++) {
	leds [ Sector ] = CRGB(red, green, blue);
	showStrip();
	// }
	//  for (int i = Sector; i < 120; i++) {
	//    leds[i] = CHSV(GP, 255, 255);
	//  }
	//  for (int i = 120; i < 138; i++) {
	//    leds[i] = CHSV(BP, 255, 255);
	//  }
	//  for (int i = 138; i < 174; i++) {
	//    leds[i] = CHSV(YP, 255, 255);
	//  }
}
void cylon () {
	static uint8_t hue;
	for (int i = 0; i < NUM_LEDS; i++) {
		EVERY_N_MILLISECONDS_I(thisdelay, 10) {
			thisdelay = THIS_DELAY;
			hue += HUE_SPEED;
		}
		leds [ i ] = CHSV(hue + RP, 255, 255);
		showStrip();
		//hue += HUE_SPEED;
		fadeall();
		delay(SPEED_DELAY);
	}
		for (int i = (NUM_LEDS) - 1; i >= 0; i--) {
		EVERY_N_MILLISECONDS_I(thisdelay, 10) {
			thisdelay = THIS_DELAY;
			hue += HUE_SPEED;
		}
		leds [ i ] = CHSV(hue + RP, 255, 255);
		showStrip();
		//hue += HUE_SPEED;
		fadeall();
		delay(SPEED_DELAY);
	}
}
void confetti ()
{
	// random colored speckles that blink in and fade smoothly
	static uint8_t hue;
	static int position;
	EVERY_N_MILLISECONDS_I(thisdelay, 200) {
		position = random16(NUM_LEDS);
		thisdelay = YP * 3;
		leds [ position ] = CHSV(hue + random8(RP), 255, 255);
	}
	fadeToBlackBy(leds, NUM_LEDS, 255 - BP);

	hue += HUE_SPEED;
	//Serial.println(hue);
	//delay(SPEED_DELAY);

//	showStrip();
}

void igor (int PAL) {
	currentPalette = Pallist [ PAL ];
	static uint8_t startIndex = 0;
	startIndex += (map(analogRead(POT4), 0, 1000, -4, 4)) / 2; /* motion speed */
	FillLEDsFromPaletteColors(startIndex);
	FastLED.delay(10);
}
void BouncingBalls (byte red, byte green, byte blue, int BallCount) {

	float Gravity = -9.81;
	int StartHeight = 1;

	float Height [ BallCount ];
	float ImpactVelocityStart = sqrt(-2 * Gravity * StartHeight);
	float ImpactVelocity [ BallCount ];
	float TimeSinceLastBounce [ BallCount ];
	int Position [ BallCount ];
	long ClockTimeSinceLastBounce [ BallCount ];
	float Dampening [ BallCount ];

	for (int i = 0; i < BallCount; i++) {
		ClockTimeSinceLastBounce [ i ] = millis();
		Height [ i ] = StartHeight;
		Position [ i ] = 0;
		ImpactVelocity [ i ] = ImpactVelocityStart;
		TimeSinceLastBounce [ i ] = 0;
		Dampening [ i ] = 0.90 - float(i) / pow(BallCount, 2);
	}

	while (pos == 14) {
		BallCount = map(analogRead(POT4),0,1023,1,BALL_COUNT);
		for (int i = 0; i < BallCount; i++) {
			TimeSinceLastBounce [ i ] =
			        millis() - ClockTimeSinceLastBounce [ i ];
			Height [ i ] =
			        0.5 * Gravity * pow(TimeSinceLastBounce [ i ] / 1000, 2.0) + ImpactVelocity [ i ] * TimeSinceLastBounce [ i ] / 1000;

			if (Height [ i ] < 0) {
				Height [ i ] = 0;
				ImpactVelocity [ i ] = Dampening [ i ] * ImpactVelocity [ i ];
				ClockTimeSinceLastBounce [ i ] = millis();

				if (ImpactVelocity [ i ] < 0.01) {
					ImpactVelocity [ i ] = ImpactVelocityStart;
				}
			}
			Position [ i ] = round(Height[i] * (NUM_LEDS - 1) / StartHeight);
		}
		BallCount = map(analogRead(POT4),0,1023,1,BALL_COUNT);
		for (int i = 0; i < BallCount; i++) {
			setPixel(Position [ i ], RB, GB, BB);
		}
		BallCount = map(analogRead(POT4),0,1023,1,BALL_COUNT);
		FastLED.setBrightness(WP);
		showStrip();
		setAll(0, 0, 0);

		//  if(pos!=14){
		// 	return;}
	}
}
void CylonBounce (byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) {

	for (int i = 0; i < NUM_LEDS - EyeSize - 2; i++) {
		if (pos != 15) {
			return;
		}
		setAll(0, 0, 0);
		setPixel(i, RB / 10, GB / 10, BB / 10);
		for (int j = 1; j <= EyeSize; j++) {
			setPixel(i + j, RB, GB, BB);
		}
		setPixel(i + EyeSize + 1, red / 10, green / 10, blue / 10);
		showStrip();
		SpeedDelay = SPEED_DELAY;
		delay(SpeedDelay);
	}

	delay(ReturnDelay);

	for (int i = NUM_LEDS - EyeSize - 2; i > 0; i--) {
		if (pos != 15) {
			return;
		}
		setAll(0, 0, 0);
		setPixel(i, RB / 10, GB / 10, BB / 10);
		for (int j = 1; j <= EyeSize; j++) {
			setPixel(i + j, RB, GB, BB);
		}
		setPixel(i + EyeSize + 1, red / 10, green / 10, blue / 10);
		showStrip();
		SpeedDelay = SPEED_DELAY;
		delay(SpeedDelay);
	}
	delay(ReturnDelay);
}
void bpm ()
{
	// colored stripes pulsing at a defined Beats-Per-Minute (BPM)
	static uint8_t gHue = HUE_SPEED;

	uint8_t BeatsPerMinute = BP / 3;
	CRGBPalette16 palette = PartyColors_p;
	uint8_t beat = beatsin8(BeatsPerMinute, 64, 255);
	for (int i = 0; i < NUM_LEDS; i++) { //9948
		leds [ i ] =
		        ColorFromPalette(palette, gHue + (i * 2), beat - gHue + (i * 10));
	}
}
void RGBLoop () {
	for (int j = 0; j < 3; j++) {
		// Fade IN
		for (int k = 0; k < 256; k++) {
			switch (j)
			{
				case 0:
					setAll(k, 0, 0);
					break;
				case 1:
					setAll(0, k, 0);
					break;
				case 2:
					setAll(0, 0, k);
					break;
			}
			showStrip();
			delay(3);
		}
		// Fade OUT
		for (int k = 255; k >= 0; k--) {
			switch (j)
			{
				case 0:
					setAll(k, 0, 0);
					break;
				case 1:
					setAll(0, k, 0);
					break;
				case 2:
					setAll(0, 0, k);
					break;
			}
			showStrip();
			delay(3);
		}
	}
}
void FadeInOut (byte red, byte green, byte blue) {
	while (pos == 4) {
		float r, g, b;
		for (int k = 0; k < 256; k = k + 1) {
			r = (k / 256.0) * red;
			g = (k / 256.0) * green;
			b = (k / 256.0) * blue;
			setAll(r, g, b);
			showStrip();
		}
		for (int k = 255; k >= 0; k = k - 2) {
			r = (k / 256.0) * red;
			g = (k / 256.0) * green;
			b = (k / 256.0) * blue;
			setAll(r, g, b);
			showStrip();
		}
	}
}
void fadeall () {
	for (int i = 0; i < NUM_LEDS; i++) {
//leds [ i ].fadeToBlackBy(250);
		leds [ i ].nscale8(BP);
	}
}
void setPixelHeatColor (int Pixel, byte temperature) {
	byte t192 = round( (temperature / 255.0) * 191);
	// calculate ramp up from
	byte heatramp = t192 & 0x3F; // 0..63
	heatramp <<= 2; // scale up to 0..252
	// figure out which third of the spectrum we're in:
	if (t192 > 0x80) {                    // hottest
		setPixel(Pixel, 255, 255, heatramp);
	} else if (t192 > 0x40) {            // middle
		setPixel(Pixel, 255, heatramp, 0);
	} else {                               // coolest
		setPixel(Pixel, heatramp, 0, 0);
	}
}

void Fire (int Cooling, int Sparking, int SpeedDelay) {
	static byte heat [ NUM_LEDS ];
	int cooldown;
	// Step 1.  Cool down every cell a little
	for (int i = 0; i < NUM_LEDS; i++) {
		cooldown = random(0, ( (Cooling * 10) / NUM_LEDS) + 2);
		if (cooldown > heat [ i ]) {
			heat [ i ] = 0;
		} else {
			heat [ i ] = heat [ i ] - cooldown;
		}
	}
	// Step 2.  Heat from each cell drifts 'up' and diffuses a little
	for (int k = NUM_LEDS - 1; k >= 2; k--) {
		heat [ k ] = (heat [ k - 1 ] + heat [ k - 2 ] + heat [ k - 2 ]) / 3;
	}
	// Step 3.  Randomly ignite new 'sparks' near the bottom
	if (random(255) < Sparking) {
		int y = random(7);
		heat [ y ] = heat [ y ] + random(160, 255);
		//heat[y] = random(160,255);
	}
	// Step 4.  Convert heat to LED colors
	for (int j = 0; j < NUM_LEDS; j++) {
		setPixelHeatColor(j, heat [ j ]);
	}
	showStrip();
	delay(SpeedDelay);
}
void colorWipe(){
  for(int i=0; i<NUM_LEDS; i++) {
      leds[i]=CHSV(BP,255,255);
      showStrip();
      delay(SPEED_DELAY);

  }
}
