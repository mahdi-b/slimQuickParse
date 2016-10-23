from collections import Counter
import random
from Bio.Seq import Seq
primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313]

alphabet={'A', 'C', 'G', 'T'}
k=4
kmers = ["".join(x) for x in itertools.product(alphabet,repeat=k)]

s0="AGGTAGTCACATACTGCGTCTGGATGGGACAACGTAAGATTCCATCATACTATTCTCCGATGGTTTTAAATGCCGAGGCGATGTTGGAACGTACGTCAGG"
s2="AGGTAGTCACATACTGCGTCTAGATGGGACAACGTAAGATTCCATCATACTATTCTCCGATGGTTTTAAATGACGAGGCGATGTTGGAACGTACGTCAGG"
s0_rc = str(Seq(s0).reverse_complement())
s2_rc = str(Seq(s2).reverse_complement())


c0 = Counter([s0[x:x+k] for x in range(len(s0)-(k-1))])
c2 = Counter([s2[x:x+k] for x in range(len(s2)-(k-1))])
c0_rc = Counter([s0_rc[x:x+k] for x in range(len(s0_rc)-(k-1))])
c2_rc = Counter([s2_rc[x:x+k] for x in range(len(s2_rc)-(k-1))])


def returnBand(size=23):
    return sorted(random.sample(range(4**k),size))


def computeSignature(band, kmers, counter):
    total = 0
    for val in band:
        total += primes[val] * counter[kmers[val]]
    return total

bands = [returnBand(11) for x in range(128)]


