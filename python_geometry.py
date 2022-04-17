# The function calc_angle_vectors calculates the angle between two vectors and is written
# for verification purposes only.
def calc_angle_vectors(vector1, vector2):
    vec_1 = vector1/np.linalg.norm(vector1)
    vec_2 = vector2/np.linalg.norm(vector2)
    dot_product = np.dot(vec_1, vec_2)
    angle = np.arccos(dot_product)
    return np.degrees(angle)

# The function rot_one_on_two rotates a vector (vector1) around another vector (vector2) by
# provided angle 
def rot_one_on_two(vector1, vector2, angle):
    comp_parallel = vector2*(np.dot(vector1, vector2) / np.dot(vector2, vector2))
    comp_normal = vector1 - comp_parallel
    b_cross_a_norm = np.cross(vector2, comp_normal)
    rotated_vector = comp_parallel + (comp_normal * np.cos(angle))+(linalg.norm(comp_normal) * (b_cross_a_norm / linalg.norm(b_cross_a_norm)) * np.sin(angle))
    return (rotated_vector)
