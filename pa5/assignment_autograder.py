#!/usr/bin/python3

from fullyAssociative import autograder as fullyAssociative_autograder
from directMapped import autograder as directMapped_autograder
from setAssociative import autograder as setAssociative_autograder
from loopInterchange import autograder as loopInterchange_autograder
from cacheOblivious import autograder as cacheOblivious_autograder

total = 0

total += fullyAssociative_autograder.grade_fullyAssociative ( path="fullyAssociative/", verbose=False )
total += directMapped_autograder.grade_directMapped ( path="directMapped/", verbose=False )
total += setAssociative_autograder.grade_setAssociative ( path="setAssociative/", verbose=False )
total += loopInterchange_autograder.grade_loopInterchange ( path="loopInterchange/", verbose=False )
total += cacheOblivious_autograder.grade_cacheOblivious ( path="cacheOblivious/", verbose=False )

print ("Score on assignment: {} out of 120.".format(total))
