# Band check

A Doppler motion sensor falls under 47 CFR §15.245, the FCC section for field-disturbance sensors. §15.23 permits me as an individual to operate home-built Part 15 equipment, five units or fewer, not marketed, built with good engineering practice to meet the provided limits. The 3cm amateur ham band ends at 10.5 GHz, so 10.525 GHz sits outside of it anyway.

§15.245(b) allows 10,500 to 10,550 MHz at a field strength of 2,500 mV/m measured at 3 m. Solving for EIRP limit:

```
EIRP = E^2*d^2/30 = (2.5 V/m)^2 * (3m)^2 / 30 = 1.875 W = 32.7 dBm
```

The HB100's EIRP is about 20 dBm, roughly 13 dB under the limit. This figure comes from the datasheet's maximum EIRP and is not measured on this unit. The real margin is at least this.

**Exposure:** According to 47 CFR §1.1310(e)(1), Table 1, general population/uncontrolled: a device with a frequency range of 1,500 to 100,000 MHz must have a limit 1.0 mW/cm² averaged over 30 minutes.

For the HB100:

```
20 dBm = 0.1 W
power density S = EIRP / (4π d²)
at d = 0.10 m:  0.1 / (4π × 0.01) = 0.80 W/m² = 0.080 mW/cm²
```

The HB100 is continuous, so the 30 minute average is just that instantaneous value, and that is 12.5x under at 10 cm.

The 21 GHz second harmonic falls above the 17.7 GHz line in the rule, so a 25 mV/m limit applies to it. However, I am unable to measure it, as my spectrum analyzer (tinySA) tops out at 5.3 GHz.
