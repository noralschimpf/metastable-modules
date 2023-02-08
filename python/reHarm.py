import numpy as np


def harmonic_entropy(p1: float, p2: float):
    # TODO: FOLLOW ALONG WITH XENWIKI
    # https: // en.xen.wiki / w / Harmonic_entropy  # Basic_Model:_Shannon_Entropy
    # P4, M3, m3, M6, m7, M2, m6, M7, TT, m2
    intv = int(np.abs(p1 * 12 - p2 * 12))
    harm_series = [x / (x - 1) if x > 1 else x for x in range(31)]
    intvs_by_harm = []


def reharm(cvs: list, harsh: float):
    cvs.sort()

    # call harmonic entropy() for each neighbor pitch set

    adj_cvs = cv_noise(cvs)
    new_cvs = []

    while len(adj_cvs) != 0:
        adj_cvs, new_cvs = prune_cv_fixes(adj_cvs, new_cvs)
        adj_cvs = cv_heuristic(adj_cvs)
        # also incorporate cv_noise()?

    return new_cvs


def cv_noise(cvs: list):
    noise = cvs
    return noise


def prune_cv_fixes(adj: list, new: list) -> (list, list):
    return adj, new


def cv_heuristic(adj: list) -> list:
    """
    given noised pitches, re-align toward a minimally-stable pitch ratio
    :param adj:
    :return:
    """
    return adj
