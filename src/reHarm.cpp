#include "plugin.hpp"


struct ReHarm : Module {
	enum ParamId {
		HARSH_PARAM,
		SHUFFLE_PARAM,
		PARAMS_LEN
	};
	enum InputId {
		PITCH_INPUT,
		TRIGGER_INPUT,
		INPUTS_LEN
	};
	enum OutputId {
		PITCH_OUTPUT,
		DOUBLEDPITCH_OUTPUT,
		OUTPUTS_LEN
	};
	enum LightId {
		LIGHTS_LEN
	};

	ReHarm() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN, LIGHTS_LEN);
		configParam(HARSH_PARAM, 0.f, 1.f, 0.f, "");
		configParam(SHUFFLE_PARAM, 0.f, 1.f, 0.f, "");
		configInput(PITCH_INPUT, "");
		configInput(TRIGGER_INPUT, "");
		configOutput(PITCH_OUTPUT, "");
		configOutput(DOUBLEDPITCH_OUTPUT, "");
	}

	void process(const ProcessArgs& args) override {
		/*
		harshness levels define acceptable final intervals using harmonic entropy
		https://en.wikipedia.org/wiki/Paul_Erlich 
		https://en.wikipedia.org/wiki/Paul_Erlich#/media/File:Harmonic_entropy_Farey_sequence.png
		//TODO: future iterations will add a context menu for other intonation systems (no TET). for now, this is hard-coded to TET
		0: do not change octaves
		1: octave changes must fit multiples of P5
		from here, interval additions follow:
		P4, M3, m3, M6, m7, M2, m6, M7, TT, m2
		*/

		//TODO: Define more algorithms, check VHDL book
		/*
		shuffle level determines the algorithm used to shuffle channels
		0: do not shuffle
		1: rotate left
		2: rotate right
		3: ...
		4: ...
		5: randomize
		*/

		/*
		ALGORITHM
		1. quantize pitches to intonation system
		2. adjust octaves
		3. calculate harmonic entropies
		4. repeat 3 & 4 until all pitches meet requirement
		5. shuffle channels
		*/
	}
};


struct ReHarmWidget : ModuleWidget {
	ReHarmWidget(ReHarm* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/reHarm.svg")));

		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(15.24, 25.81)), module, ReHarm::HARSH_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(15.24, 46.063)), module, ReHarm::SHUFFLE_PARAM));

		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.688, 94.472)), module, ReHarm::PITCH_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(20.49, 94.472)), module, ReHarm::TRIGGER_INPUT));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(8.0, 115.694)), module, ReHarm::PITCH_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(22.0, 115.694)), module, ReHarm::DOUBLEDPITCH_OUTPUT));

		// mm2px(Vec(28.0, 22.881))
		addChild(createWidget<Widget>(mm2px(Vec(1.25, 228.5))));
	}
};


Model* modelReHarm = createModel<ReHarm, ReHarmWidget>("reHarm");