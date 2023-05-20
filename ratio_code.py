def calculate_ratios(current, current_est,voltage, voltage_est, oc, oc_est):
    ir = current_est / float(current)
    vr = voltage_est / float(voltage)
    ocr = oc_est / float(oc)
    return ir, vr, ocr