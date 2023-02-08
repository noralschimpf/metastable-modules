import unittest
import numpy as np
import reHarm as rh

cv_seqs = [np.zeros(5), np.random.random(5) * 10, np.zeros(1), np.random.random(1) * 10]

class TestReharm(unittest.TestCase):


    # what test data should be generated?
    def setUp(self) -> None:

    def tearDown(self) -> None:


    def test_singlePitch(self):

    def test_unisonPitches(self):

    def test_pitchSpread(self):

    def test_negativeValues(self):


class TestEntropy(unittest.TestCase):


    def setUp(self) -> None:


    def tearDown(self) -> None:


    def test_singlePitch(self):

    def test_unisonPitches(self):

    def test_pitchSpread(self):

    def test_negativeValues(self):



class TestNoise(unittest.TestCase):
    # def setUp(self) -> None:
    # def tearDown(self) -> None:


    def test_isChanged(self):
        for i in range(len(cv_seqs)):
            with self.subTest(cvs=cv_seqs[i]):
                self.assertNotEqual(rh.cv_noise(cv_seqs[i]), cv_seqs[i])



class TestHeuristic(unittest.TestCase):
    def setUp(self) -> None:
    def tearDown(self) -> None:

    def test_singlePitch(self):

    def test_unisonPitches(self):

    def test_pitchSpread(self):

    def test_negativeValues(self):


def suite():
    suite = unittest.TestSuite()
    suite.addTest(TestEntropy)
    suite.addTest(TestNoise)
    suite.addTest(TestPrune)
    suite.addTest(TestHeuristic)
    suite.addTest(TestReharm)
    return suite


if __name__ == '__main__':
    runner = unittest.TextTestRunner()
    runner.run(suite())