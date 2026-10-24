class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        soln = []

        for i in range(0, len(nums1)):
            index = 0
            for j in range(0, len(nums2)):
                if (nums1[i] == nums2[j]):
                    index = j

            found = False

            for k in range(index, len(nums2)):
                if (nums2[k] > nums1[i]):
                    soln.append(nums2[k])
                    found = True
                    break
            
            if found == False:
                soln.append(-1)
        
        return soln
        
        