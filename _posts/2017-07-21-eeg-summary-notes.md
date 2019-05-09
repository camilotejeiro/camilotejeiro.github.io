---
title: Electroencephalography (EEG) Summary Notes
---

This is a quick summary/digest on EEG (_for personal future reference only_). 
Content credits include (_use these as factual references instead_): 

* [Electroencephalography Wikipedia Article](https://en.wikipedia.org/wiki/Electroencephalography)

* [IFCN standards for digital recording of clinical EEG](https://www.ncbi.nlm.nih.gov/pubmed/10590972)

* [ACNS EEG Guidelines](https://www.acns.org/practice/guidelines)

* [IEC EEG Standards](https://webstore.iec.ch/publication/2637)

## Introduction

Electroencephalography (EEG) measures voltage fluctuations resulting from 
Ionic currents within the neurons of the brain (Sum of groups of neurons in 
localized areas a opposed to individual neurons). In clinical contexts, EEG 
refers to the recording of the brain's spontaneous electrical activity over a 
period of time -- as recorded from multiple electrodes placed on the scalp.

Diagnostic applications normally focus on the frequency spectral content of EEG,
to identify different types of neural oscillations (i.e. brain waves)

## Applications

Used in the diagnosis of:

* Epilepsy
* Sleep disorders
* Coma
* Encephalopathies
* Brain Death

Also used in the past in the diagnosis of:

* Tumors
* Stroke
* other focal brain disorders.

_But largely replaced by MRI and CT scanning technology_

## Mechanisms

The brain's electrical charge is maintained by millions of neurons. The
electrical potential generated by an individual neuron is far too small to be
picked up by EEG. EEG Activity therefore always reflects the summation of the
synchronous activity of thousands or millions of neurons that have similar
spatial orientation. 

_If the cells do not have similar spatial orientation, their ions do not line 
up to create waves to be detected_

_Also, because voltage fields gradients fall off with the square of distance,
activity from deep sources is more difficult to obtain than currents near the
skull_

Scalp EEG activity shows oscillations at a variety of frequencies -- brain
waves. Several of these oscillations have characteristic frequency ranges,
spatial distributions and are associated with different states of brain
functioning (e.g. walking and the various sleep stages). **These oscillation or
waves represent synchronized activity over a network of neurons.**

EEG reflects correlated synaptic activity caused by post-synaptic potentials of
cortical regions.

## Methods

In scalp EEG, normally the recording is obtained by placing electrodes on the
scalp with conductive gel (or paste). Usually after preparing the area with
light abrasion to remove dead cells. Many systems use individual electrodes,
others use caps or nets with embedded electrodes (mostly when high-density
electrode arrays are needed).

### Electrodes Placement

Electrode locations are largely standardized by the International 10-20 system.

Name reflects the fact that electrodes are placed at intervals that are 10% or
20% of the distance between landmarks in the skull.

- Front to back landmarks: nasion to inion.
- Left to right landmarks: pre-auricular points.

For higher density electrode arrays the 10-10 system is used: places electrodes
at 10% intervals.

### Channel Count 

In most clinical applications 19 recording electrodes (plus ground and system 
reference) are used.

### Signal's Amplitude (Scalp EEG) 

A typical adult human EEG signal is about 10 uV - 100 uV in amplitude when 
measured from the scalp (in optimal conditions). 

However 1 uV to 100 uV is a more realistic conservative estimate under most 
typical cases. 

_EEG acquisition systems should be designed to operate with a 
1 uV to 1 mV dynamic input range._

### Signal's Noise

Noise amplitude is usually 2x to 10x larger than signal amplitude.

Noise can be from multiple sources: 

* Ambient noise (external): 50/60HZ main-line hum, fluorescent lights, RF high-frequency
noise from cell-phones and other RF sources (aliased when under-sampled).

* Biopotentials noise (internal): Noise from other biopotentials e.g. EMG, EOG,
ECG, EDA ...etc. These are very often greater in amplitude than EEG signals.

_In theory these are all common-mode signals, so should be removed by good
common-mode-rejection (CMR) technicques._ **Thus the importance of high 
CMRR (common mode rejection ratio) in EEG acquisition systems**

### Electrodes Montages

* Sequential Montage (also called bipolar): Each channel represents 
the difference between two adjacent electrodes.

* Referential Montage: Each channel represents the difference between a certain
electrode and a designated "reference" electrode. There is no standard position
for this electrode but it is normally at a different position than the
recording electrodes.

* Average Reference Montage: The outputs of the amplifiers are summed and
averaged and this averaged signal is used as the common reference for each
channel

* Laplacian Montage: Each channel represents the difference between an electrode 
and a weighted average of the surrounding electrodes.

With digital EEG, all signals are typically digitized in a particular (usually
referential) montage, since any other montage can be constructed mathematically
from any other.

## Limitations of EEG

Several limitations: 

* Most importantly **poor spatial resolution**: EEG is most sensitive to a
    particular set of post-synaptic potentials -- those generated in superficial
    layers of the cortex. In contrast, those generated deeper in the cortex 
    have far less contributions to EEG.

* EEG recordings do not directly capture axonal action potentials.

* EEGs show a preference for activity on populations of parallel dendrites,
    transmitting current in the same direction and at the same time.
 
_Thus, EEG provides information with a large bias to selected neuron types,_ and
generally should not be used to make general claims about localized brain activity 
e.g. the meninges, cerebrospinal fluid and skull "smear" the EEG signal, obscuring
its source.

## EEG Clinical Standards/Organizations

There are three main organizations that publish standards ruling EEG acquisition
systems:

1. International Federation of Clinical Neurophysiology (IFCN): main widely
    cited standard though rather dated (1998).

2. American Clinical Neurophysiology Society (ACNS): Mostly focused at
    clinicians and medical researchers, less focus on hardware (references
    IFCN).

3. International Electrotechnical Commission (IEC): widely used among device
    manufacturers, only paid access. Standards retrieved from applicable data in
    open access publications.

## EEG System's Design solutions

This is a rough very general description of the two opposite ends of design 
approaches used widely in industry:

1. The traditional discrete "mostly analog" approach: no longer viable. 

    - Instrumentation Amplifiers Inputs: (High Zin, high CMRR)
    - Analog High Pass Filter (0.1Hz): reject dc electrode offset.
    - Low-noise amplifier 
    - Anti-aliasing Low-pass filter (~100Hz): necessary before SAR AD conversion.
    - Sample and hold circuit (to prevent time skewing of EEG signals).
    - Analog Multiplexer.
    - 12-16 bit SAR AD conversion (single channel). 

    Cons: **Typically** greater component count, greater PCB area, greater power
    consumption, greater cost and lower overall performance (component's miss-match in
    path to AD conversion) as compared to newer more integrated multi-channel
    delta-sigma ADC solutions.

2. The multi-channel delta-sigma ADC approach: **more widely used in
industry today**
 
    _Delta-sigma ADCs have become very affordable and their data rates and effective 
    resolution have continued to increase. Higher levels of integration have made 
    these almost a single-chip solution_.

    - Differential I/O On-chip Programmable Gain Amplifiers: High Zin, Low noise. 
    - Bias-drive amplifier (also called Driven Right Leg): for setting 
        common-mode DC voltage (reducing electrode's offset) and increasing system CMRR.  
    - on-chip 16-24 bit Delta-sigma multi-channel differential ADCs: Relaxes 
        necessity of anti-aliasing high-order low pass filters at ADC inputs, 
        differential conversion increases CMRR.

    _The low amplitude, low frequency bandwidth of EEG signals, makes delta-sigma
    ADCs (typically higher-resolution yet lower speed than SAR ADCs) especially well 
    suited to this application._

{% include issues_comments.md %}